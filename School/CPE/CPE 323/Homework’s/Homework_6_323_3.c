#include <msp430F5529.h>
#include <stdbool.h>

bool Buzzer_Enabled = false;

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;   // Stopping the watchdog timer
    __enable_interrupt();       // Enable interrupts globally

    TA0CCTL0 = CCIE;            // Enabled TimerA interrupt
    TA0CCR0 = 4;                // 4 / 32768 Hz = 0.125ms or 8KHZ
    TA0CTL = TASSEL_1 + MC_1;   // ACLK, up mode

    P4DIR |= 0x02;              // P4.2 is output direction for buzzer.
    P4REN |= BIT2;              // Enable the pull-up resistor at P4.2
    P4OUT &= ~0x02;             // Buzzer is off at start.

    P4DIR &= ~BIT4;             // Set P4.4 as input (External Switch)
    P4REN |= BIT4;              // enable pull-up resistor
    P4OUT |= BIT4;

    P4IE  |= BIT4;              // Configuring switch on P4.4 interrupt.
    P4IES |= BIT4;
    P4IFG &= ~BIT4;

    _BIS_SR(LPM0_bits + GIE);   // Enter Low Power Mode 0
}

// External Switch Press.
#pragma vector = PORT4_VECTOR
__interrupt void PORT4_ISR(void)
{
    P4IFG &= ~BIT4;             // Clear interrupt flag.
    Buzzer_Enabled ^= true;     // Set the Buzzer to true.
    P4IES ^= BIT4;              // Toggles External Switch edge select.
}

//TimerA Interrupt Service Routine
#pragma vector = TIMER0_A0_VECTOR
__interrupt void timerA_isr()
{
    if(Buzzer_Enabled)
    {
        P4OUT ^= 0x02;          // Toggle the buzzer at 8KHZ. 4 up toggles it. 
    }
}




