;-------------------------------------------------------------------------------
; File       :	calc_power.asm
; Function   :	This file takes the data off of the stack, stores it into registers
;				and uses those register values to perform operations
; Description:	calc_power takes the data off the stack and initializes different data.
; Input      :	Input comes from main.asm which is really just the stack data.
; Output     :	Output is in the memory browser.
; Author     : 	N. Anderson  npa0002@uah.edu
; Date       : 	09/30/2020
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"   ; Include device header file
            .def 	calc_power			; Define the calc_power function.
			.ref	SW_Mult				; Reference to the Software multiplier file.
            .ref	HW_Mult				; Reference to the Hardware multiplier file.
            .text

calc_power:
			mov   	6(SP), R5			; Move the Software array address into R5
			mov		4(SP), R6			; Move the Hardware array address into R6
			mov		2(SP), R7			; Move the result into R7
			mov		#1, R12				; R12 will get 1 for the first iteration of the software loop.
			jmp		SWLoop				; Jump to the SWLoop, it will carry out from there.

SWLoop:		call	#SW_Mult			; Call the software multiplier.
			incd	R5					; Increment R5 to the next index.
			dec		R8					; Decrement R8 (counter).
			jnz 	SWLoop				; Jump not zero back to software loop.
			mov 	#5, R8				; reset power counter

HWLoop:		call 	#HW_Mult			; Call the hardware muliplier.
			incd 	R6					; Increment to the next index.
			dec		R8					; Decrement the counter.
			jnz		HWLoop				; Jump not zero back to hardware loop.

lend:
			nop

