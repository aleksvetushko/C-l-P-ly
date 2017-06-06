
; *************** CHAR_COUNT SETUP ******************************

   .orig x3300 ; begin at x3300

CHAR_COUNT  ; save space for return value
   ADD R6, R6, #-1 ; decrement R6, this will be return val

   ; push return address
   ADD R6, R6, #-1 ; decrement R6, this will be ret addr
   STR R7, R6, #0 ; store ret addr (R7)

   ; push dynamic link
   ADD R6, R6, #-1 ; decrement R6, this will be dyn link (R5)
   STR R5, R6, #0 ; store dyn link (R5)

   ; new frame pointer
   ADD R5, R6, #-1 ; R5 is the address one above the dyn link (start of local vars)

   ; new stack pointer
   ADD R6, R6, #-1 ; R6 points to the start of local vars as well (result)

; *************** CHAR_COUNT CODE ******************************

   ; int result;
   AND R0, R0, #0 ; clear R0
   STR R0, R5, #0 ; store R0 in address of R5 (first local var)

   ; if(*str == 0) result = 0;
   LDR R0, R5, #4 ; load value of address in (R5+4) (address of string) into R0
   LDR R0, R0, #0 ; load ascii value of string into R0
   BRnp NOTNULL ; if first char is negative or positive branch to NOTNULL
   AND R1, R1, #0 ; clear R1
   STR, R1, R5, #0 ; store 0 in result
   BRnzp DONE ; go to DONE

NOTNULL ; else, if(*str == c) result = 1;
   LDR R1, R5, #5 ; load c into R1
   NOT R1, R1 ; not c
   ADD R1, R1, #1 ; add 1 to c (we convert c to a negative number)
   ADD R1, R1, R0 ; check if char == c
   BRnp NOTC ; if char != c branch to NOTC
   AND R1, R1, #0 ; clear R1
   ADD R1, R1, #1 ; add 1 to R1 (result is 1)
   STR, R1, R5, #0 ; store 1 in result
   BRnzp RECUR

NOTC ; else, result = 0;
   AND R1, R1, #0 ; clear R1
   STR R1, R5, #0 ; store 0 in result

RECUR ; result += charCount(str+1, c);
   LDR R1, R5, #4 ; put address of string char into R1
   ADD R1, R1, #1 ; add R1 so R1 is address of next string char
   LDR R2, R5, #5 ; load c into R2

	; push second parameter
   ADD R6, R6, #-1 ; decrement R6
	STR R2, R6, #0	; push c onto the stack

	; push first parameter
	ADD R6, R6, #-1 ; decrement R6
	STR R1, R6, #0	; push address of next str char onto the stack

   ; call function
	LEA R0, CHAR_COUNT
	JSRR R0


; *************** CHAR_COUNT RETURN ******************************

DONE ; return result;
   LDR R0, R5, #0 ; load result into R0
   LDR R1, R6, #0 ; load return value
   ADD R0, R0, R1 ; add result and return value
   STR R0, R5, #3 ; store result in return val (R5+3)

   ; pop local vars
   ADD R6, R5, #1 ; R6 = R5 + 1

   ; pop dynamic link
   LDR R5, R6, #0 ; load address at dynamic link spot into R5
   ADD R6, R6, #1 ; pop link off stack

   ; restore return address
   LDR R7, R6, #0 ; load address in R6 (return address) into R7
   ADD R6, R6, #1 ; pop ret addr off stack

   RET
   .END
