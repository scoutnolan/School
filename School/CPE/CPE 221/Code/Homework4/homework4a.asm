; int abs(int)
; int b_minus_a(int,int)
; int a_minus_b (int,int)
; int main()
;{
;	int a = -b;
;	int b = -9;
;	while(a != b)
;		if (a < b) 
;		{
;			b = b_minus_a(a,b)
;}
;int abs(int x)
;{
;	if(x < 0)
;		x = -x;
;	return x;
;}
;int a_minus_b(int x, int y)
;{
;	x = x - y;
;	return x;
;}
;int b_minus_a(int x, int y)
;{
;	y = y - x
;	return y;
;}



			AREA homework4a.asm, CODE, READWRITE
			ENTRY
			LDR		r4, a						; loads a into r0
			LDR 	r5, b						; loads b into r1
			LDR		r0, [r4]					; loads address of r4 into r0
			CMP 	r0, #0						; compare r0 and 0
			BLLT	abs							; branch to abs function if it is less than 0
			STR 	r0, [r4]					; r4<-r0
			LDR 	r1, [r5]
			CMP 	r1, #0						; compare r0 and 0
			BLGT	abs							; branch to abs function if it is less than 0
			STR		r1, [r5]
Loop		CMP 	r0, r1						; loop to compare r0 and r1
			BEQ		WhileExit					; exit loop if they equal each other
			BLLT 	b_minus_b					; if r0(a) is less than r1(b), b minus a.
			STR 	r0, [r0]
			BLGT	a_minus_a					; if r0(a) is greater than r1(b), a minus b.
			STR     r1, [r1]
			B 		Loop						; repeat while true
WhileExit	Post 	Loop						; exit loop


abs			MOV     r1, #-1
			MUL     r2, r0, r1
			MOV     r0, r2
			MOV     r8, #47
			PUSH    {r8}
done    	STR     r0, abs_num


a_minus_b   SUB 	r0, r0, r1
			MOV 	pc, lr
			
b_minus_b   SUB		r1, r1, r0					; sub b = b - a	
			MOV 	pc, lr						; " " 
			
			
a			DCD		-8							;
b			DCD		 9							;
abs_num 	SPACE	 4							;
			END


;
;	CPE 221 Assembly Example
;    
;   This example demonstrates basic subroutine call capability.
;	
;   int Func1 (int);
;   int main()
;   {
;      int P = 3;
;      int Q = -1;
;      P = Func1(P);
;      Q = Func1(Q);
;   }
;   int Func1(int x)
;   {
;     if (x > 0) 
;       x = 16*x + 1;
;     else
;       x = 32*x; 
;   ;
	

        AREA SUBROUTINE_CALL, CODE, READWRITE
        ENTRY
        ADR   r4, P
		ADR   r5, Q
		LDR   r0, [r4]
		BL    Func1
		STR   r0, [r4]
		LDR   r0, [r5]
		BL    Func1
		STR   r0, [r5]
done    B     done
Func1   CMP   r0, #0
        MOVGT r0, r0, LSL #4
        ADDGT r0, r0, #1
        MOVLE r0, r0, LSL #5
		MOV   pc, lr
        AREA  SUBROUTINE_CALL, DATA, READWRITE
P       DCD   3
Q       DCD   -1
        END
			
			
			
			;
;	CPE 221 Assembly Example
;    
;   This example demonstrates nested subroutine call capability.
;	
;   int Func1 (int);
;   int Times16 (int);
;   int main()
;   {
;      int P = 3;
;      int Q = -1;
;      P = Func1(P);
;      Q = Func1(Q);
;   }
;   int Func1(int x)
;   {
;     if (x > 0) 
;       x = Times16(x) + 1;
;     else
;       x = 32*x;
;     return(x);
;   }
;   int Times16(int x)
;   {
;     x = 16*x;
;     return(x);
;   }

        AREA NESTED_SUBROUTINE_STACK_NO_BL, CODE, READONLY
        ENTRY
        ADR   r4, P
		ADR   r5, Q
		LDR   r0, [r4]
        SUB   sp, sp, #4
        STR   pc, [sp]
		BAL   Func1
		STR   r1, [r4]
		LDR   r0, [r5]
		SUB   sp, sp, #4
		STR   pc, [sp]
		BAL   Func1
		STR   r1, [r5]
done    BAL     done
Func1   CMP   r0, #0
        SUBGT sp, sp, #4
		STRGT pc, [sp]
		BLGT  Times16
        ADDGT r1, r1, #1
        MOVLE r1, r0, LSL #5
        LDR   r12, [sp], #4
        SUB   pc, r12, #4
Times16 MOV   r1, r0, LSL #4
        LDR   r12, [sp], #4
		SUB   pc, r12, #4
        AREA  NESTED_SUBROUTINE_STACK_NO_BL, DATA, READWRITE
P       DCD   3
Q       DCD   -1
        END






	