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
            ;.data


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
             	sub.w   #12, SP
              	mov.w   SP, R6
              	mov.w   #myinput, R4
gnext:			mov.b   @R4+, R5
             	cmp.b   #0, R5
             	jz      lend
             	cmp.b   #'A', R5
            	jl      lcopy
             	cmp.b   #'Z'+1, R5
             	jl      lconv
            	jmp     lcopy
lconv:			sub.b   #'A', R5
	           	add.b   #'a', R5
lcopy:			mov.b   R5, 0(R6)
             	inc.w   R6
             	jmp     gnext
lend:       	mov.b   R5, 0(R6)
             	jmp     $               ; jump to current location '$' (endless loop)21
myinput:    .cstring "CPE325-lab"
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



