;* ALL RIGHTS RESERVED.  COPYRIGHT 2002, MICROCHIP TECHNOLOGY INCORPORATED USA.  
;* INFORMATION CONTAINED IN THIS PUBLICATION REGARDING DEVICE APPLICATIONS AND 
;* THE LIKE IS INTENDED THROUGH SUGGESTION ONLY AND MAY BE SUPERSEDED BY UPDATES.  
;* NO REPRESENTATION OR WARRANTY IS GIVEN AND NO LIABILITY IS ASSUMED BY 
;* MICROCHIP TECHNOLOGY INCORPORATED WITH RESPECT TO THE ACCURACY OR USE OF SUCH 
;* INFORMATION, OR INFRINGEMENT OF PATENTS ARISING FROM SUCH USE OR OTHERWISE.  
;* USE OF MICROCHIP'S PRODUCTS AS CRITICAL COMPONENTS IN LIFE SUPPORT SYSTEMS IS 
;* NOT AUTHORIZED EXCEPT WITH EXPRESS WRITTEN APPROVAL BY MICROCHIP.  NO LICENSES 
;* ARE CONVEYED, IMPLICITLY OR OTHERWISE, UNDER ANY INTELLECTUAL PROPERTY RIGHTS"
;* *******************************************************************/
;* Discrete Fourier Transform
;* - init_sine_table places 8-bit signed 32-sample sine wave into FTABLE[32]
;* - Time domain input samples stored in INBUFFER[32]
;* - dft correlates FTABLE against INBUFFER to create IBIN and QBIN results
;* - (16) 24-bit Imaginary and Real frequency bin results stored in IBIN and QBIN

	#include p18f46k20.inc
	
;FTABLE 	size=32 bytes (32) 8-bit sine table	
;IBIN 		size=48 bytes (16) 24-bit Real frequency sum bins
;QBIN 		size=48 bytes (16) 24-bit Imaginary frequency sum bins
;INBUFFER 	size=32 bytes (32) 8-bit samples
;BINCOUNT 	size=1  byte  Bin counter varible
;MSB_TEMP 	size=1  byte  MSB of bin counter for 2's complement calculations

	extern FTABLE,IBIN,QBIN,INBUFFER,BINCOUNT,MSB_TEMP 
	global dft,init_sine_table
	
	ERRORLEVEL -315		; Turn off LFSR assembler warnings, LFSR works on PIC18FXXX devices
	ERRORLEVEL -314
	
	code
dft
	banksel	BINCOUNT
	lfsr	0,FTABLE		; FSR0 points to the start of sine frequency table
	lfsr	1,INBUFFER		; FSR1 points to the start of the input sample buffer
	lfsr	2,IBIN			; FSR2 points to the Real frequency sum bin
	clrf	BINCOUNT		; Point to first I-Bin table entry
	call	loop_bin		; Perform I-bin Multiply and Accumulate operation
	lfsr	0,FTABLE+8		; FSR0 points to the start of cosine frequency table
	lfsr	1,INBUFFER		; FSR1 points to the start of the input sample buffer
	lfsr	2,QBIN			; FSR2 points to the imaginary frequency sum bin
	clrf	BINCOUNT		; Point to first Q-bin table entry
	call	loop_bin		; Perform Q-bin Multiply and Accumulate operations
	call	abs_bin			; Now convert magnatude from 2's complement to unsigned
	return

correlation macro	
	local add_negative
	local add_positive
	clrf	MSB_TEMP		; Clear MSB of MAC result
	movf	INDF0,W			; Move next input sample waveform value to W register
	mulwf	POSTINC1		; Multiply input sample by correlated frequency wave value
	btfss	FSR0L,4			; Skip if correlated waveform is negative
	bra		add_positive	; Correlated waveform is positive so don't take 2's complement
add_negative
	comf	PRODL,F			; Convert result to negative 2's complement number
	comf	PRODH,F			; Invert product result and temporary 24-bit MSB register
	comf	MSB_TEMP		; 
	movlw	1				; Officially, we should add one after complementing
	addwf	PRODL,F			; but this simply result in a offset of 16 that will show up in all bins
	movlw	0
	addwfc	PRODH,F
	addwfc	MSB_TEMP,F
add_positive
	movf	PRODL,W			; Add product low to I or Q bin LSB, point to next byte in bin			
	addwf	POSTINC2,F
	movf	PRODH,W			; Add product high to I or Q bin MSB, point to next byte in bin
	addwfc	POSTINC2,F
	movf	MSB_TEMP,W		; Move MSB into W register to add carry from product high I or Q bin result to MSB byte of bin
	addwfc	POSTDEC2,F
	movf	POSTDEC2,F		; Decrement I or Q pointers to reset them to beginning of this bin
	incf	BINCOUNT,W		; Skip to next sine / cosine input value 
	addwf	FSR0L,W
	andlw	0x1F			; Module sine / cosine correlation table by 32
	movwf	FSR0L
	endm

loop_bin
	clrf	MSB_TEMP		; Clear MSB of MAC result
	bcf		FSR1L,5			; Modulo 32 the input sample waveform pointer
	movf	INDF0,W			; Place sine table value into W register
	mulwf	POSTINC1		; Multiply sample by sine table, place result into PROD register
	btfss	FSR0L,4			; Skip if correlated waveform is negative
	bra		add_positive	; Correlated waveform is positive so don't take 2's complement
add_negative
	comf	PRODL,F			; Convert result to negative 2's complement number
	comf	PRODH,F			; First invert the product result
	comf	MSB_TEMP		; Now add 1 to the inverted result...
	movlw	1				; Officially, we should add one after complimenting to it...
	addwf	PRODL,F			; but this simply result in a offset of 16 that will show up in all bins
	clrw
	addwfc	PRODH,F
	addwfc	MSB_TEMP,F
add_positive
	movff	PRODL,POSTINC2		; Initialize bin with the first corelation results
	movff	PRODH,POSTINC2
	movff	MSB_TEMP,POSTDEC2			
	movf	POSTDEC2			; Reset pointer to LSB of current bin
	incf	BINCOUNT,W			; Point to next entry in frequency sine wave frequency
	addwf	FSR0L,W				
	andlw	0x1F				; Modulo-32 in sine frequency table
	movwf	FSR0L
correlate
	local i
i = .31
	while (i > 0)
	correlation					; Perform correlation macro (24-bit) sum FTABLE * INBUFFER (31) more times
i--
	endw
	incf	BINCOUNT,F			; Point to next bin and sine wave frequency
	btfsc	BINCOUNT,4			; Skip when if we have not finshed the last bin
	return						; done with all bins so return
	movlw	0x3					; Advance I or Q pointer to next bin by adding 3 locations
	addwf	FSR2L,F
	bra		loop_bin			; Not done with this bin so loop back

abs_bin							; Convert IBIN and QBIN results from 2's complement to absolute magnatude
	lfsr 	0,IBIN+0x5F			; Point FSR0 to the MSB of the last value in IBIN
loop_abs
	movlw	IBIN-1				; Place first IBIN entry (minus 1) into WREG for comparison
	cpfseq	FSR0L			    ; Skip if we are finished with IBIN and QBIN
	bra		check_negative		; Not done yet so check next value
	return						; Return once we are finished
check_negative
	btfss	INDF0,7				; Skip if this is a negative number
	bra    	abs_positive 		; Not negative, so we don't need to complement
abs_negative	
	comf	POSTDEC0,F			; Negative number, so compliment it to make it positive
	comf	POSTDEC0,F
	comf	POSTDEC0,F
	bra	loop_abs
abs_positive
	movf	POSTDEC0,F			; Positive number, so move FSR0 (3) positions to point it to the next 24-bit entry
	movf	POSTDEC0,F	
	movf	POSTDEC0,F
	bra		loop_abs	

init_sine_table					; Initializes FTABLE[32] with 2's complements sine table
	lfsr	0,FTABLE			; Point to the start of the sin table in RAM
	movlw	upper	sine_table	; Init MSB of table pointer to beginning of sine table
	movwf	TBLPTRU	
	movlw	HIGH	sine_table	; Init middle byte of table pointer to beginning of sine table
	movwf	TBLPTRH	
	movlw	low	sine_table		; Init LSB of table pointer to beginning of sine table
	movwf	TBLPTRL
	movlw	0x20
	movwf	BINCOUNT			; Initialize BINCOUNT to 32 entries
loop_sine_lookup
	tblrd*+						; Read byte from sine lookup table, place in TABLAT
	movff	TABLAT,POSTINC0		; Place sine look-up byte into next entry of RAM based sine table
	decfsz	BINCOUNT,F			; Decrement counter, skip when zero
	bra		loop_sine_lookup	; Not done initializing RAM table, loop back
	return						; Done with last entry so return
			
sine_table			; 2's complement sine table
	data	0x03200	; Sample Numbers	0	 and 	1
	data	0x08E62	; Sample Numbers	2	 and 	3
	data	0x0D4B4	; Sample Numbers	4	 and 	5
	data	0x0FAEC	; Sample Numbers	6	 and 	7
	data	0x0FAFF	; Sample Numbers	8	 and 	9
	data	0x0D4EC	; Sample Numbers	10	 and 	11
	data	0x08EB4	; Sample Numbers	12	 and 	13
	data	0x03262	; Sample Numbers	14	 and 	15
	data	0x03200	; Sample Numbers	16	 and 	17
	data	0x08E62	; Sample Numbers	18	 and 	19
	data	0x0D4B4	; Sample Numbers	20	 and 	21
	data	0x0FAEC	; Sample Numbers	22	 and 	23
	data	0x0FAFF	; Sample Numbers	24	 and 	25
	data	0x0D4EC	; Sample Numbers	26	 and 	27
	data	0x08EB4	; Sample Numbers	28	 and 	29
	data	0x03262	; Sample Numbers	30	 and 	31

	end		
	
	
