;-------------------------------------------------------------------------------
; File       : main.asm (CPE 325 Lab4 Q1 Code)
; Function   : Counts the number of words and sentences in a string
; Description: Program traverses an input array of characters
;              to detect number of words and sentences
; Input      : The input string is specified in myStr
; Output     : The port P1OUT displays the number of E's in the string
; Author     : N. Anderson  npa0002@uah.edu
; Date       : September 19, 2020
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
            .data
sent_count:          .int        0       ;
w_count:             .int        0       ;
myStr:      .cstring "Hello I am sentence one. Sentence two is better!"
            ; string variable shown above.
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.
;-------------------------------------------------------------------------------
RESET:       mov.w   #__STACK_END,SP         ; Initialize stackpointer
			 mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer
;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------
main:
        mov.w        #myStr, R4         ; move string into R4
        clr.b        R5                 ; clear R5 for counter   
        clr.b        R7                 ; clear R7 for counter 

next    mov.b       @R4+, R6            ; R6 gets the next character in R4     
        cmp.b       #0, R6              ; compare R6 value to NULL character
        jeq         lend                ; if it is a NULL jump to end.
        cmp.b       #' ', R6            ; compare R6 to a space, this is not working correctly.
        jeq       	word                ; incrememnt word counter
        cmp.b       #'.', R6            ; compare R6 to period
        jeq         sent                ; jump to count if yes
        cmp.b       #'?', R6            ; compare R6 to '?'
        jeq         sent                ; jump to count if yes
        cmp.b       #'!', R6            ; comapre R6 to '!'
        jeq         sent                ; jump to count if yes
        jne         next                ; if not go back to next.

word	inc.w		R5					; increment word counter
        jmp 		next				; jump to next

sent    inc.w       R7                  ; incrememnt sentence character
        jmp         next                ; jump to next

lend:   inc.w		R5						; increment the word counter since some strings do not end in a space.
		mov.w       R7, &sent_count         ; move counter into sentence count
        mov.w       R5, &w_count            ; move counter into word count.
        nop                                 ; required only for Debugger
;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
        .global __STACK_END
        .sect   .stack

;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
         .sect   ".reset"               ; MSP430 RESET Vector
         .short  RESET
         .end
