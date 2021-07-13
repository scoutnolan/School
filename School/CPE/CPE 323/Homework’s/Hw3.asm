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
mya:		.byte	4, 5, 6, -10, 55, 64, -100
;mya2:		.byte	5, 6, 127, 154, -4, 25, 10
myaa:
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
       	mov.w	#mya, R14
       	mov.w	#myaa, R13
       	sub.w	R14, R13
       	mov.w	#0xC8, R7
MyLoop:	mov.b	@R14+, R15
		cmp.b   R7, R15		;-100 < 64
		jl		lskip
		mov.b	R15, R7
lskip:	dec.w	R13			; do not update R7
		jnz		MyLoop
		mov.b	R7, P1OUT
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
