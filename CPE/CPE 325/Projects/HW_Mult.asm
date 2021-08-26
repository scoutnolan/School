;-------------------------------------------------------------------------------
; File       :	HW_mult.asm
; Function   :	To perform a hardware multiplication on predefined values
; Description:	This file will take in values and use hardware multiplication to
;				find the powers from 1-5
; Input      :	R4 and R7 from main and calc_power.asm
; Output     :	See memory browser
; Author     : 	N. Anderson  npa0002@uah.edu
; Date       : 	09/30/2020
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"      ; Include device header file
            .def HW_Mult
            .text
HW_Mult:

			mov 	R4, &MPY			; move R4 into the unsinged 16 bit multiplication register, unsigned multiplication
			mov 	R7, &OP2			; move R4 into the general purpose operator. multiply by...
			nop
			nop
			nop
			mov 	RESLO, R7			; move the result the R7.
			mov     R7, 0(R6)			; move result  into R6
			ret


