; Aleks Vetushko
; Ashish Sethi
; asgn3

      .ORIG x3300; this is trap x26

MTRAP ; R0 is address of string
      AND R1, R1, #0 ; stores KBSR
      AND R2, R2, #0 ; stores KBDR
      AND R3, R3, #0 ; incremented address of string
      ADD R3, R0, #0 ; incremented address of string
      AND R4, R4, #0 ; DSR
      AND R5, R5, #0 ; DDR

GETCH LDI R1, A ; load A (KBSR) into R1
      BRzp GETCH ; if KBSR isn't negative keep checking
      LDI R2, B ; load KBDR (B) into R2
      ADD R2, R2, #-10 ; check if R2 is 'Enter'
      BRz EXIT ; if R2 is enter go to EXIT
      ADD R2, R2, #10 ; otherwise add 13 back to R2
      STR R2, R3, #0 ; R2 is stored in incremented address R3
      ADD R3, R3, #1 ; increment R3

OUTCH LDI R4, C ; load DSR into R4
      BRzp OUTCH ; if DSR isn't negative keep checking
      STI R2, D ; store R2 in address that is the value of B (DDR)
      BRnzp GETCH ; go back for the next char

EXIT  AND R1, R1, #0 ; clear R1 to store NULL at the end of the string
      STR R1, R3, #0 ; store NULL (R1) at the end of the string
      RET ; return back to task

A     .FILL xFE00 ; address of KBSR
B     .FILL xFE02 ; address of KBDR
C     .FILL xFE04 ; address of DSR
D     .FILL xFE06 ; address of DDR
      .END
