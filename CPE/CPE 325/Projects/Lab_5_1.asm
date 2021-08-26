;-------------------------------------------------------------------------------
; File       :	main.asm
; Function   :	Push data onto the stack and call a function in another file
; Description:	This file creates an array of 10 bytes for a hardware and software
;				multiplier
; Input      :	A b value to be multiplied
; Output     :	No output, see registers and memory browser.
; Author     : 	N. Anderson  npa0002@uah.edu
; Date       :	09/30/2020
;-------------------------------------------------------------------------------

            .cdecls C,LIST,"msp430.h"       ; Include device header file

;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
            .ref 	calc_power
;-------------------------------------------------------------------------------
; 		Allocation for result
			.bss	swarr, 10			;	10 bytes for software array
			.bss	hwarr, 10			;	10 bytes for hardware array
			.data
b:			.int	3					; 	int variable to intput into the code.
result:		.int	1					; 	result variable
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.
;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer
;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------
main:
			push 	#swarr			; Push the software array address onto the stack.
			push 	#hwarr			; Push the hardware array onto the stack.
			push 	result			; Push the result onto the stack.
			mov		b, R4			; Mov b into R4.
			mov		#5, R8			; Counter for the loops in calc_power.
			call 	#calc_power		; A call to the calc_power.asm file to start the loops.
			jmp		$				; jump infinetly.
lend:
			nop
;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack
;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
