; Aleks Vetushko
; Ashish Sethi
; Assignment 3

; R1 is the number they input
; R0 is used to take in user input
; R2 is the count of chars in user's message
; R3 is the original unencrypted char
; R4 holds the address of user message
; R5 checks if the char user typed is Enter

.ORIG x3000         ; start at x3000
AND R1, R1, #0      ; clear R1
AND R2, R2, #0      ; clear R2
AND R3, R3, #0      ; clear R3
LEA R4, string      ; load address of string into R4

LEA R0, message1    ; load address of message1 into R0
TRAP x22            ; print out string starting at address in R0

TRAP x20            ; read one char from KBDR, store in R0
TRAP x21            ; print char in R0
ADD R1, R0, #0      ; store the char in R1
ADD R1, R1, #-16    ; convert ASCII code of R1 to number
ADD R1, R1, #-16    ; convert ASCII code of R1 to number
ADD R1, R1, #-16    ; convert ASCII code of R1 to number

LEA R0, message2    ; load address of message2 into R0
TRAP x22            ; print out string starting at address in R0

LOOP1
   TRAP x20         ; read one char from KBDR, store in R0
   TRAP x21         ; print char in R0
   AND R3, R3, #0   ; clear R3
   ADD R3, R0, #0   ; store unencrypted char in R3

   AND R5, R0, #1   ; if R0 bit = 1 R5 is p, if bit = 0 R5 is z
   BRp POS          ; if bit is 1 go to POS
   BRz ZER          ; if bit is 0 go to ZER
POS
   ADD R0, R0, #-1  ; make the one bit zero
   BR NEXT
ZER
   ADD R0, R0, #1   ; make the zero bit one
NEXT
   ADD R0, R0, R1   ; add number 1-9 to R0
   STR R0, R4, #0   ; store this new char in string
   ADD R4, R4, #1   ; increment address of string
   ADD R2, R2, #1   ; increment counter of chars in message
   ADD R3, R3, #-10 ; if R3 is Enter, R3 is now zero
BRnp LOOP1          ; if R3 n or p (but not z), get more chars

LEA R0, message3    ; load address of message2 into R0
TRAP x22            ; print out string starting at address in R0

LEA R0, string      ; load address of string into R0
TRAP x22            ; print out string starting at address in R0

LEA R4, string      ; load address of string into R0
ENDL
AND R0, R0, #0      ; clear R0
STR R0, R4, #0      ; store null char in string
ADD R4, R4, #1      ;increment string addr
ADD R2, R2, #-1     ; decrement counter of chars
BRp, ENDL           ; go back

HALT

message1 .STRINGZ "Encryption Key (1-9): "
message2 .STRINGZ "\nInput Message: "
message3 .STRINGZ "Encrypted Message: "
string .BLKW #21

.END
