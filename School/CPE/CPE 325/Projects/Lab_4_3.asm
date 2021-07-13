;-------------------------------------------------------------------------------
; File       : main.asm (CPE 325 Lab4 Q2 Code)
; Function   : Updates the value of the lowercase letters to upper case
; Description: This program reads a string and converts
;				the lower case to upper case
; Input      : The input string is specified in myStr
; Output     : None, just updated register values.
; Author     : N. Anderson  npa0002@uah.edu
; Date       : September 19, 2020
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
            .data
myStr:      .cstring "I enjoy learning msp430"				; string character
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
        mov.w 		#myStr, R4          ; move string into R4
        clr.b           R5                  ; Pointer to the R6 address
qnext:  mov 		R4, R5				; move R4 into R5 for the value.
        mov.b           @R4+, R6            ; R6 gets the next character
        cmp.b           #0, R6              ; compare R6 value to NULL character
        jeq             lend                ; if it is a NULL jump to end.
        cmp.b 		#97, R6		    ; compare 97 to R6
        jc		upper		    ; switch to upper case if it is greater than 97
        jmp		qnext		    ; jump back to qnext
upper
        cmp.b		#123, R6			; compare to 123
        jc		qnext				; if it is greater than jump to qnext
        sub		#32, R6				; update the address' value
        mov.b   	R6, 0(R5)			; R5+0 <- R6
        jmp		qnext				; jump to qnext for the next value.
lend:   nop                                 ; required only for Debugger
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
