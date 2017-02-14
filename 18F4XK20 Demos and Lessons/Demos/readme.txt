PIC18F4XK20 Starter Kit Demonstration

The PIC18F4XK20 Starter Kit is a starter and development kit for the new PIC18F4XK20 microcontroller family.  The new microcontroller family takes advantage of Microchip’s latest process technology.  Key features are low power consumption, low cost, and high performance operation.  

Hardware Required
- PIC18F4XK20 Starter Kit Board
- PICKit 2 Programmer
- Microphone headset (for DFT Demo)

Overview

There are 3 hex files that will be included with the current demo:

- DFT.hex
o The DFT demo requires a microphone headset or input.  The input is sampled at 5 kHz on the microcontroller ADC.  32 samples of ADC values are stored.  The values are convolved with a sine and cosine tables to determine an imaginary and real result.  The magnitude is calculated and scaled to fit the OLED display.  

The plotted 16 point DFT is a spectrum analysis of the input signal from 0-2500 Hz.  The Nth bar in the graph represents (N * 156.25 Hz) bins.  

(note: use the Gain potentiometer to adjust input gain.  Turning right increases gain.)

- RTC.hex
o The real time clock demo uses the Low Power Timer1 Oscillator to generate the time base for the real time clock.  12 Hr time is shown on the display.  +m increments minutes while +h increments hours.  

- PongDemo.hex
o This game is played to 5 and the score is shown on the bottom of the screen.  The buttons on the left control the up and down motion of the left bar while the right buttons control the right side.



