#ifndef XC_SETBAUD_H
#define	XC_SETBAUD_H

#define CLOSEST_UBRG_VALUE ((FCY+8ul*BAUD_RATE)/16/BAUD_RATE-1)
#define BAUD_ACTUAL (FCY/16/(CLOSEST_UBRG_VALUE+1))
#define BAUD_ERROR ((BAUD_ACTUAL > BAUD_RATE) ? BAUD_ACTUAL-BAUD_RATE : BAUD_RATE-BAUD_ACTUAL)
#define BAUD_ERROR_PRECENT    ((BAUD_ERROR*100+BAUD_RATE/2)/BAUD_RATE)
#if (BAUD_ERROR_PRECENT > 3)
    #warning UART frequency error is worse than 3%
#elif (BAUD_ERROR_PRECENT > 2)
    #warning UART frequency error is worse than 2%
#endif

#endif	/* XC_HEADER_TEMPLATE_H */

