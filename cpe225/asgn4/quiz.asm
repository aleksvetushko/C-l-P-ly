; Aleks Vetushko
; Ashish Sethi
; asgn3

         .ORIG x3000
BEGIN    AND R0, R0, #0 ; R0 holds the inputs and outputs
         AND R1, R1, #0 ; R1 holds the memory location of values
         AND R2, R2, #0 ; R2 holds the point total
         AND R5, R5, #0 ; store PC in R5

         LD R0, Q1 ; load address of Q1 into R0
         PUTS ; print out Q1
         LEA R5, A1 ; load PC into R5
         JSR GETINT ; get answer from user
A1       LD R1, Q1Answ ; load address Q1Answ into R1
         ADD R1, R1, #-1 ; decrement R1 so that you can add the integer to it
         LEA R5, A2 ; load PC into R5
         JSR POINTV ; determine point value of answer

A2       LD R0, Q2 ; load Q1 into R0
         PUTS ; print out Q1
         LEA R5, A3 ; load PC into R5
         JSR GETINT ; get answer from user
A3       LD R1, Q2Answ ; load Q1Answ into R1
         ADD R1, R1, #-1 ; decrement R1 so that you can add the integer to it
         LEA R5, A4 ; load PC into R5
         JSR POINTV ; determine point value of answer

A4       LD R0, Q3 ; load Q1 into R0
         PUTS ; print out Q1
         LEA R5, A5 ; load PC into R5
         JSR GETINT ; get answer from user
A5       LD R1, Q3Answ ; load Q1Answ into R1
         ADD R1, R1, #-1 ; decrement R1 so that you can add the integer to it
         LEA R5, A6 ; load PC into R5
         JSR POINTV ; determine point value of answer

A6       LEA R5, BEGIN ; load start of program into R5 so we can loop
         ADD R2, R2, #-5 ; load CC
         BRn Fin1 ; if R2 is negative
         ADD R2, R2, #-5
         Brn Fin2 ; if R2 is negative
         ADD R2, R2, #-5
         Brn Fin3 ; if R2 is negative
         ADD R2, R2, #-4
         Brn Fin3 ; if R2 is negative
         HALT

         Fin1 LD R0, Result1
              PUTS
              JMP R5 ; start it over
         Fin2 LD R0, Result2
              PUTS
              JMP R5 ; start it over
         Fin3 LD R0, Result3
              PUTS
              JMP R5 ; start it over
         Fin4 LD R0, Result4
              PUTS
              JMP R5 ; start it over


GETINT   LEA R0, PROMPT ; load prompt into R0
         PUTS ; ask for integer
         GETC ; get answer, store in R0
         OUT ; echo answer
         ADD R0, R0, #-16 ; convert ASCII to hex
         ADD R0, R0, #-16 ; convert ASCII to hex
         ADD R0, R0, #-16 ; convert ASCII to hex
         JMP R5 ; go back to PC

POINTV   ADD R1, R0, R1 ; go to address of point value you need
         LDR R0, R1, #0 ; store point value in R0
         ADD R2, R2, R0 ; add point value in R0 to total points in R2
         JMP R5 ; go back to PC (right after JSR POINTV)

PROMPT   .STRINGZ "\nAnswer: "

Q1       .FILL x3300
Q1Answ   .FILL x339A
Q2       .FILL x339E
Q2Answ   .FILL x3420
Q3       .FILL x3424
Q3Answ   .FILL x34A4
Q4       .FILL x34A8
Q4Answ   .FILL x3500

Result1  .FILL x3504
Result2  .FILL x350A
Result3  .FILL x3510
Result4  .FILL x3514

         .END
