///*------------------------------------------------------------------------------
//* Student:      Nolan Anderson
//* Program:      Lab_3_1.c
//* Date:         Aug 21, 2121
//* Input:        None
//* Output:       No output, but output of the LED's on the board.
//* Description:  This c program interfaces with switches and LED's on the MSP430
//*               By accessing the pins on the board itself. Also uses debouncing
//*               and program delay in order to blink the leds.
//*-----------------------------------------------------------------------------*/
#include <msp430.h>                 // Including the board directive.
#define S1PUSH ((P2IN&BIT1) == 0)   // Here I am defining the Switch 1 and switch 2 for if they are pushed.
#define S2PUSH ((P1IN&BIT1) == 0)
#define RED 0x01                    // Here I am defining the red and green LED's for their pin values on the board
#define GREEN 0x80                  // LED 1 = RED, LED 2 = GREEN

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;       // STOP Watchdog timer

    P1DIR |= RED;                   // P1.0 is output direction for 0x01, or red.
    P1REN |= BIT1;                  // Enable the pull-up resistor at P1.1
    P1OUT |= BIT1;                  // LED is on.
    P4DIR |= GREEN;                 // P4.7 is output for 0x80, or green.
    P2REN |= BIT1;                  // Enable pull-up resistor at P2.1
    P2OUT |= BIT1;                  // LED is on
    int i = 0;                      // Loop counter
    for( ; ; )                                  // infinite loop so that it is always reading input
    {
        if (S1PUSH)                             // If switch 1 is pressed
        {
            for (i = 2000; i > 0; i--);               // Loop through until it runs out,
            while (S1PUSH && !S2PUSH)                   // While Switch 1 is pressed
            {
                P4OUT &= ~GREEN;                // Green LED stays off.
                __delay_cycles(500000);         // This is a delay cycle for the hz rate. so every time the loop goes through
                                                // It delays 2hz
                P1OUT ^= RED;                   // Toggle the red LED
            }
        }
        else if (S2PUSH)                        // If switch 2 is pressed.
        {
            for (i = 2000; i > 0; i--);        // For all of these values, loop through from 10,000->0. Basically will never run out.
            while(S2PUSH && !S1PUSH)
            {
                P1OUT |= RED;                   // Here, I turn on the Red LED
                __delay_cycles(200000);         // This is a delay cycle for the hz rate. so every time the loop goes through
                                                // It delays by 5hz
                P4OUT ^= GREEN;                 // And I toggle the green LED
            }
        }
        else                            // Else, for all times that the button is not pressed, do the following:
        {
        P4OUT |= GREEN;                 // Here, the Green LED is on,
        P1OUT &= ~RED;                  // And the Red LED is off
                                        // Until a something changes on the switches.
        }
    }
}

