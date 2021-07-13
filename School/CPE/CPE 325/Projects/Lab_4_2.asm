;-------------------------------------------------------------------------------
; File       : main.asm (CPE 325 Lab4 Q2 Code)
; Function   : Runs a mathematical expression from a string
; Description: This program reads a string of numbers and operators
;              and performs the operation.
; Input      : The input string is specified in myStr
; Output     : The port P2OUT displays the result of the operation
; Author     : N. Anderson  npa0002@uah.edu
; Date       : September 19, 2020
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
            .data
myStr:      .cstring "4-3+5"				; string character
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
        mov.w 			#myStr, R4          ; move string into R4
        clr.b           R5                  ; clear R5 for final number
qnext:  
        mov.b           @R4+, R6            ; R6 gets the next character
        cmp.b           #0, R6              ; compare R6 value to NULL character
        jeq             lend                ; if it is a NULL jump to end.
        cmp.b           #'+', R6            ; compare R6 to +
        jeq             aop 	            ; if yes, jump to aop to add
        cmp.b           #'-', R6            ; compare R6 to -
        jeq             sop                 ; if yes, jump to sop to sub
		mov.b			R6, R5				; If no, store R6 in R5. This will essentially
											; get the first number in the operation to start.
		jmp				qnext				; jump to get next character (should be operation)

aop		mov.b			@R4+, R6			; increment the counter and move it to R7
		add             R6, R5				; R5 <- R5 + R7
		sub     		#48, R5				; this is necessary to keep the running total correct
        jmp             qnext				; Get next character.

sop    	mov.b			@R4+, R6			; Increment the counter and move it to R6
		sub             R6, R5				; R5 <- R5 + (not) R7 + 1
		add     		#48, R5				; this is necessary to keep the running total correct
        jmp             qnext				; Get the next character.

lend:   sub				#48, R5				; R5 <- R5 + (not) 48 + 1
        mov.b       	R5, &P2OUT          ; write result in P2OUT (not visible on port pins)
        nop                                 ; required only for Debugger
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
