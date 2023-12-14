;-------------------------------------------------------------------------------
; File       :   SW_Mult.asm
; Function   :  This files function is to perform software multiplication on a value
; Description:  This file takes in R7 and R4 and uses shift - add - multiplication
;			    to find the powers of 4 from 1-5
; Input      :	R4 and R7 from main and calc_power.asm
; Output     :	See memory browser
; Author     :	 N. Anderson  npa0002@uah.edu
; Date       :	09/30/2020
;-------------------------------------------------------------------------------
			.cdecls C,LIST,"msp430.h"      ; Include device header file
			.def SW_Mult
			.text
SW_Mult:
			mov 	#10, R9 		; Initializing a bit counter.
			mov 	#0, R10 	; Initialize the result number to R10.
			mov		R4, R11 	; Move b into R11 so that we can perform operations w/o changing its value
			jmp 	bitcheck	; Jump straight to bitcheck.

bitcheck:
			mov 	R12, R13 	; Mov b into R13 so that we can perform operations without changing its value
			and 	#0x01, R13	; bitchecking to see if the LSB is 1
			cmp 	#0x01, R13 	; Cmopare operation for previous AND instruction
			jne 	noadd		; If it is not equal (i.e. = 0) then skip the add instruction.
			add 	R11, R10	; Add to the running total
			jmp 	noadd		; Go straight to s
noadd:
			rrc 	R12			; Shift B to right by 1.
			rla 	R11			; Shift A left by 1.
			dec 	R9 			; Decrement the bit counter.
			jnz 	bitcheck	; If bit counter is not zero, go to next bit to add.
			mov 	R12, R13	; If it is 0, move the result into R13.
			and 	#0x10, R13	; Check to see if it is a negative number
			cmp 	#0x10, R13 	; If it is negative, jump to subtract from A from result.
			jeq 	neg			; Jump if equal to negative
			jmp 	end			; Unconditionally jump to end
neg:
			sub 	R11, R10	; Sub instruction for negative numbers
			jmp 	end			; Unconditionally jump to end.
end:
			mov 	R10, 0(R5)	; Move the result into the next part of the
			mov 	R10, R12 	; Put the result into B for the next power operation.
			ret					; Return back to calc_power.asm

