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
RESET:      mov.w   #__STACK_END,SP         ; Initialize stack pointerStopWDT:
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer
;-------------------------------------------------------------------------------
; Main code here
;-------------------------------------------------------------------------------
		sub.w   #4, SP                  ; allocate space for ascii chars
		mov.w   SP, R14                 ; R14 points to the allocated area
		mov.w   myI, R4                 ; integer is passed through R4
		mov.w	array, R11				; making space for the new character array.
		push.w  R14                     ; push the starting address on the stack
		call    #i2a_s                  ; call subroutine
		add.w   #2, SP                  ; free space on the stacklend:
		jmp 	$
myI:    .word     0x34AE
array:
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

i2a_s:
			mov.w	R4, R5					; Copy value of R4 into R5
			and.b	#0x0F, R5				; R5 wil; have 0x0003
			jmp		rotate					; jump to rotate subroutine, Rotate the R4 value [0xE34A]

			mov.w	R4, R6					; Copy value of R4 into R6
			and.b	#0x0F, R6				; R5 wil; have 0x0004
			jmp		rotate					; jump to rotate subroutine, Rotate the R4 value [0xAE34]

			mov.w	R4, R7					; Copy value of R4 into R6
			and.b	#0x0F, R7				; R7 will have 0x000A
			jmp		rotate					; jump to rotate subroutine, Rotate the R4 value  [0x4AE3]

			mov.w	R4, R8					; Copy value of R4 into R6
			and.b	#0x0F, R8				; R8 will have 0x000E
			jmp		rotate					; jump to rotate subroutine, Rotate the R4 value [0x34AE]

			mov.b	R5, R10					; copy R5 into R10
			jmp		compare					; Jump To Compare
			mov.b	R10, R5					; Update R5

			mov.b	R6, R10					; copy R6 into R10
			jmp		compare					; Jump To Compare
			mov.b	R10, R6					; Update R6

			mov.b	R7, R10					; copy R7 into R10
			jmp		compare					; Jump To Compare
			mov.b	R10, R7					; Update R7

			mov.b	R8, R10					; copy R8 into R10
			jmp		compare					; Jump To Compare
			mov.b	R10, R8					; Update R8

			mov.b	R8, 0(R11)				; Move the value into the first part of R11
			mov.b	R7, 1(R11)				; Move the value into the second part of R11
			mov.b	R6, 2(R11)				; Move the value into the third part of R11
			mov.b	R5, 3(R11)				; Move the value into the fourth part of R11
			ret

rotate:		rra		R4						; Rotate R4 for next bit
			rra		R4						; Rotate R4 for next bit
			rra		R4						; Rotate R4 for next bit
			rra		R4						; Rotate R4 for next bit

compare:	cmp.b 	#0x0A, R10				; compare A to R7
			jl		number					; If it is less than, then this is a number.
			jge		letter					; If it is greater than, then we know that it is a letter.

letter:
			add		#0x37, R10				; converting to hex
			ret

number:		add		#0x30, R10				; converting to hex
			ret
