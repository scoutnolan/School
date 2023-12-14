;------------------------------------------------------------------------------
; Student:      Nolan Anderson
; Program:      Lab_6_1.asm
; Date:         Aug 20, 2020
; Input:		Switch one and 2 on the board.
; Output:		The red LED blinks three times and toggles the second LED, and the LED2 simply toggles
; Description:  When switch one is pressed, LED1 simply blinks three times at 1Hz and then
;				toggles LED2. When switch 2 is pressed, LED 2 simply toggles off and on.
;-----------------------------------------------------------------------------*/
            .cdecls C,LIST,"msp430.h"       ; Include device header file
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
            .def	SW1_ISR					; Define the SW1_ISR function.
            .def	SW2_ISR					; Define the SW2_ISR function.
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.
;-------------------------------------------------------------------------------
RESET:       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT:     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer
;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------
; bic: bit clear, and bis, bit set.
; P1.0 is Red LED, P4.7 is Green LED
; P1.1 is switch 2, P2.1 is switch 1
SETUP:
			bis.b	#0x01, &P1DIR		; Set P1.0 as output, 0'b0000 0001
			bis.b	#0x80, &P4DIR		; Set P4.7 as output, 0'b1000 0000
			bic.b	#0x01, &P1OUT		; Turn P1.0 off.
			bic.b	#0x80, &P4OUT		; Turn P4.7 off.
			; Setting the Switch 2's data (i/o).
			bic.b	#0x02, &P1DIR		; Set P1.1 as input for SW2
            bis.b	#0x02, &P1REN		; Enable Pull-Up resister at P1.1
            bis.b	#0x02, &P1OUT		; required for proper IO set up
			; Setting the Switch 1's data (i/o).
            bic.b	#0x02, &P2DIR		; Set P2.1 as input for SW1
            bis.b	#0x02, &P2REN		; Enable Pull-up resistor at P2.1
			bis.b	#0x02, &P2OUT		; Required for proper IO setup.
			; Declaring interrupts and bits.
            bis.w	#GIE, SR			; Enable Global Interrupts
            bis.b	#0x02, &P1IE		; Enable Port 1 interrupt from bit 1
			bis.b	#0x02, &P1IES		; Set interrupt to call from hi to low
			bis.b	#0x02, &P2IE		; Enable Port 2 interrupt from bit 1
			bis.b	#0x02, &P2IES		; Set interrupt to call from hi to low
			bic.b	#0x02, &P1IFG		; Clear interrupt flag
			bic.b	#0x02, &P2IFG		; Clear interrupt flag


Start:		cmp		#1, R5				; Compare 1 to R5
			jne		RLED				; If it is not one, jump to the Red LED function.
			clr		R5					; Clear the status of R5
			xor.b	#0x01, &P1OUT		; Toggles the Red LED

RLED:		cmp		#1, R6				; Compare 1 to R6
			jne 	Loop				; If it is one, then switch to the infinite loop.
			clr		R6					; Clear the status of R6
			mov		#6, R5				; Move 6 into R5
Cycle:		mov		#0xFFFF, R7			; Move FFFF into R7, upper limit of a number.

Delay:		dec		R7					; Decrement R7.
			nop
			nop
			nop
			nop
			nop
			jnz		Delay				; If R7 is not zero, jump back to delay.
			xor.b	#0x01, &P1OUT		; Toggle the Red LED
			dec		R5					; Decrement R5
			jnz 	Cycle				; If R5 is not zero, reset the R7 value and do this again.
			bit.b	#0x01, &P1OUT		; And 0x01 and P1OUT
			xor.b	#0x80, &P4OUT		; Toggle the green LED.
			jz		Loop				; If the status bit is zero, jump to loop to restart check.
Loop:
			jmp		Start				; Loop here until interrupt
;----------------------------------------------------------------------------
; P1_0 (Red) / P2_1 (SW1) interrupt service routine (ISR)
;----------------------------------------------------------------------------
SW1_ISR:
			bic.b	#0x02, &P2IFG		; Clear interrupt flag
			bit.b	#00000010b, &P2IN	; Check if SW1 is pressed; (0000_0010 on P2IN)
			jnz		Exit1				; If not zero, SW is not pressed; loop and check again
Debounce_:	mov.b	#2000, R7			; Set to (2000 * 10 cc )
SWD20ms_:	dec		R7              	; Decrement R7
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			jnz 	SWD20ms_		 	; If R7 is 0, then the loop will break and move on.
			bit.b	#0x02, &P2IN        ; Verify SW1 is still pressed
			jnz		Exit1			 	; If not, wait for S2 press
			mov.b   #1, R6				; Move 1 into R6
Exit1:		reti					 	; Return from interrupt
;----------------------------------------------------------------------------
; P4_7 (Green) / P1_1 (SW2) interrupt service routine (ISR)
;----------------------------------------------------------------------------
SW2_ISR:
			bic.b	#0x02, &P1IFG		; Clear interrupt flag
			bit.b	#00000010b, &P1IN	; Check if S2 is pressed; (0000_0010 on P1IN)
			jnz		Exit2				; If not zero, SW is not pressed; loop and check again
			xor.b	#0x80, &P4OUT		; Toggle P4.7
Debounce:	mov.b	#2000, R7			; Set to (2000 * 10 cc )
SWD20ms:	dec.w	R7             		; Decrement R15
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			jnz 	SWD20ms				; If R7 is 0, then the loop will break and move on.
			bit.b	#0x02, &P1IN    	; Verify S2 is still pressed
			jnz		Exit2			 	; If not, wait for S2 press
			mov.b 	#1, R7				; Move 1 into R7
Exit2:		reti					 	; Return from interrupt
;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack
;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"        ; MSP430 RESET Vector
            .short  RESET
 			.sect   ".int47"        ; PORT2_VECTOR,
            .short  SW2_ISR
            .sect   ".int42"        ; PORT1_VECTOR,
            .short  SW1_ISR
            .end
