/*------------------------------------------------------------------------------
* Student:      Nolan Anderson
* Program:      main.asm
* Date:         Aug 20, 2020
* Input:        Switch 1 and 2 on the board
* Output:       The LED's blink back and forth
* Description:  This code blinks the 2 LEDs back and forth on the MSP430 and uses debouncing
*               to delay the time and blink at different rates. The code essentially uses switch
*               one to double the hz rate (no higher that 8Mhz) and switch two to halve the
*               blinking rate. (No Lower than 1Mhz)
*-----------------------------------------------------------------------------*/
#include  <msp430.h>

void configure_clock_sources();
inline void Mhz1();                     // Change cf to 1 Mhz
inline void Mhz2();                     // Change cf to 2 Mhz
inline void Mhz8();                     // Change cf to 8 Mhz
inline void Mhz4();                     // Change cf to 4 Mhz

#define REDLED 0x01;
#define GREENLED 0x80;

int counter = 1;                        // Counter to check for what Mhz rate to blink at.

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;            // Stopping the watchdog timer

    P1DIR &= ~BIT1;                      // Set P1.1 as input (SW2)
    P1REN |= BIT1;                       // enable pull-up resistor
    P1OUT |= BIT1;
    P2DIR &= ~BIT1;                      // set P2.1 as input (SW1)
    P2REN |= BIT1;                       // enable pull-up resistor
    P2OUT |= BIT1;

    _EINT();                             // enable interrupts
    P1IE  |= BIT1;                       // Enable interrupt at P1.1 for Switch 1
    P1IES |= BIT1;                       // Enable hi->lo edge for interrupt
    P1IFG &= ~BIT1;                      // Clear any errornous interrupt flag

    P2IE  |= BIT1;                       // Enable interrupt at P2.1 for Switch 2
    P2IES |= BIT1;                       // enable hi->lo edge for interrupt
    P2IFG &= ~BIT1;                      // clear any errornous interrupt flag

    configure_clock_sources();           // Configure the clock sources
    Mhz1();                              // Set initial blinking to 1 Mhz

    P1DIR |= REDLED;                     // Configure the P1.0 as output.
    P4DIR |= GREENLED;                   // Configure the P4.7 as output.

    P1OUT = P1OUT | REDLED;              // Turn on LED 1.
    P4OUT = P4OUT & ~GREENLED;           // Turn off LED 2.

    while(1)
    {
        P1OUT ^= REDLED;                 // Toggle P1.0
        P4OUT ^= GREENLED;               // Toggle P4.7
        __delay_cycles(500000);          // Delay of 250ms
    }
}


// this ISR handles the SW2 key press
#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR(void)
{
    // let us clear the flag

    P1IFG &= ~BIT1;

    //debouncing section
    __delay_cycles(25000);

    // if SW1 is not pressed, return
    if((P1IN&BIT1)!=0x00)
        return;

    if(counter == 8)        // Are we blinking at 8Mhz?
    {
        Mhz4();             // Switch to 4Mhz blinking
        counter = 4;
    }
    else if(counter == 4)   // Are we blinking at 4Mhz?
    {
        Mhz2();             // Switch to 2Mhz blinking.
        counter = 2;
    }
    else if(counter == 2)   // Are we blinking at 2 Mhz?
    {
        Mhz1();             // Switch to 4Mhz blinking.
        counter = 1;        // Switch the counter equal to 1.
    }
    else if(counter == 1)    // Are we blinking at 1 Mhz?
    {
        Mhz1();             // Switch to 1Mhz blinking.
        counter = 1;        // Keep the counter at 1.
    }
}

// this ISR handles the SW1 key press
#pragma vector = PORT2_VECTOR
__interrupt void PORT2_ISR(void)
{
    // let us clear the flag
    P2IFG &= ~BIT1;

    //debouncing section
    __delay_cycles(25000);

    // if SW1 is not pressed, return
    if((P2IN&BIT1)!=0x00)
        return;

    if(counter == 8)        // Are we blinking at 8Mhz?
    {
        Mhz8();             // Switch to 8Mhz blinking.
        counter = 8;        // Keep the counter at 8.
    }
    else if(counter == 4)   // Are we blinking at 4Mhz?
    {
        Mhz8();             // Switch to 8Mhz blinking.
        counter = 8;        // Set the counter to 8.
    }
    else if(counter == 2)   // Are we blinking at 2 Mhz?
    {
        Mhz4();             // Switch to 4Mhz blinking.
        counter = 4;        // Set the counter equal to 4.
    }
    else if(counter == 1)   // Are we blinking at 1 Mhz?
    {
        Mhz2();             // Switch to 2Mhz blinking.
        counter = 2;        // Set the counter equal to 2.
    }
}


// ***** CHANGING THE CLOCK FREQUENCY TO 1 MHZ ***** //
void Mhz1()
{
    __bis_SR_register(SCG0);                // Disable the FLL control loop
    UCSCTL1 = DCORSEL_3;                    // Select DCO range Mhz1 operation
    UCSCTL2 = 32;                           // Set DCO Multiplier for Mhz1
                                            // (N + 1) * FLLRef = Fdco
                                            // (32 + 1) * 32768 = Mhz1
    __bic_SR_register(SCG0);                // Enable the FLL control loop
    __delay_cycles(33792);                  // 32 x 32 x 1 MHz / 32,768 Hz = 33792 = MCLK cycles for DCO to settle
}

// ***** CHANGING THE CLOCK FREQUENCY TO 2 MHZ ***** //
void Mhz2()
{
    __bis_SR_register(SCG0);                // Disable the FLL control loop
    UCSCTL1 = DCORSEL_4;                    // Select DCO range Mhz2 operation,
    UCSCTL2 = 62;                           // Set DCO Multiplier for Mhz1
                                            // (N + 1) * FLLRef = Fdco
                                            // (62 + 1) * 32768 = Mhz2
    __bic_SR_register(SCG0);                // Enable the FLL control loop
    __delay_cycles(62500);                  // 32 x 32 x 2 MHz / 32,768 Hz = 62500 = MCLK cycles for DCO to settle
}

// ***** CHANGING THE CLOCK FREQUENCY TO 4 MHZ ***** //
void Mhz4()
{
    __bis_SR_register(SCG0);                // Disable the FLL control loop
    UCSCTL1 = DCORSEL_4;                    // Select DCO range Mhz4 operation
    UCSCTL2 = 124;                          // Set DCO Multiplier for Mhz1
                                            // (N + 1) * FLLRef = Fdco
                                            // (124 + 1) * 32768 = Mhz4
    __bic_SR_register(SCG0);                // Enable the FLL control loop
    __delay_cycles(125000);                 // 32 x 32 x 4 MHz / 32,768 Hz = 125000 = MCLK cycles for DCO to settle
}

// ***** CHANGING THE CLOCK FREQUENCY TO 8 MHZ ***** //
void Mhz8()
{
    __bis_SR_register(SCG0);                // Disable the FLL control loop
    UCSCTL1 = DCORSEL_5;                    // Select DCO range Mhz8 operation
    UCSCTL2 = 249;                          // Set DCO Multiplier for Mhz8
                                            // (N + 1) * FLLRef = Fdco
                                            // (249 + 1) * 32768 = Mhz8
    __bic_SR_register(SCG0);                // Enable the FLL control loop
    __delay_cycles(250000);                 // 32 x 32 x 8 MHz / 32,768 Hz = 250000 = MCLK cycles for DCO to settle
}

void configure_clock_sources()
{
    UCSCTL3 = SELREF_2;                  // Set DCO FLL reference = REFO
    UCSCTL4 |= SELA_2;                   // Set ACLK = REFO
    UCSCTL0 = 0x0000;                    // Set lowest possible DCOx, MODx
    // Loop until XT1,XT2 & DCO stabilizes - In this case only DCO has to stabilize
    do
    {
    UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);   // Clear XT2,XT1,DCO fault flags
    SFRIFG1 &= ~OFIFG;                            // Clear fault flags
    } while (SFRIFG1&OFIFG);                      // Test oscillator fault flag
}



