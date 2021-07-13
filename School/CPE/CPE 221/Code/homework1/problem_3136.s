
		AREA problem_3136, CODE, READWRITE
		ENTRY
		ADR 	r0, arrayx 					 ; pointer to first element of array x
		ADD 	r0,r0, #36					 ; go to the end of the array r0
		ADR		r1, arrayy 					 ; pointer to first element of array y
		LDR 	r2, size   					 ; r2 holds size of array
		LDR 	r3, i						 ; r3 holds loop counter
		LDR 	r5, a						 ; r5 holds a
loop 	SUBS 	r4, r3, r2					 ; computes i - size
		BMI 	done						 ; if i - size >= 0, done
		LDR 	r6, [r0]	 	 	 		 ; r6 = arrayx[size-i-1]
		ADD		r6, r6, r5					 ; r6 = arrayx[size-i-1] + a (i.e. 20)			
		STR		r6, [r1]					 ; arrayy = arrayx[size-i-1] + a
		SUB		r0, r0, #4					 ; update r0 for next element of arrayx (i.e. go back an element)
		ADD		r1, r1, #4					 ; update r1 for next element of arrayy
		ADD     r3, r3, #1					 ; increments loop counter
		B 		loop						 ; once done with iteration, go back
done	B		done						 ; infinite loop
size 	DCD 	9							 ; set size to 10
a 		DCD 	20							 ; set a to 20
arrayx	DCD		8, 2, 9, 6, 7, 0, 1, 3, 5, 4 ; initialize array x
arrayy	SPACE	40							 ; reserver memory locations for array y
i		DCD		0							 ; set i initially to 0
		END
				
				
				
				
				
;	C Code
;	int x[10] = {8, 2, 9, 6, 7, 0, 1, 3, 5, 4};
;	for i = 0; i < 10; i++)
;	y[i]] = x[size –i]+ 20;
				
				