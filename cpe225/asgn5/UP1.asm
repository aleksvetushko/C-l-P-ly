.ORIG	x3000

      LD    R1, ADDR3300
      STI   R1, ADDR26 ; stores x26
      LD    R1, ADDR3500
      STI   R1, ADDR180 ; stores interrupt
      LD    R6, ADDR3000 ; initialize stack pointer (PC)

LOOP	TRAP	x26  ; get char
      TRAP	x21  ; print char to screen
      TRAP	x26  ; get char
      TRAP	x21  ; print char to screen
      TRAP	x26  ; get char
      TRAP	x21  ; print char to screen
      TRAP	x26  ; get char
      TRAP	x21  ; print char to screen
      TRAP	x26  ; get char
      TRAP	x21  ; print char to screen
      LEA	R0, END_MSG
      PUTS
      BRnzp LOOP

      HALT

END_MSG     .STRINGZ "\nSuccess!  Running again...\n"
ADDR26      .FILL    x26 ; trap 26 vector
ADDR3300    .FILL    x3300 ; address of trap 26 code
ADDR3500    .FILL    x3500 ; address of ISR code
ADDR180     .FILL    x180 ; interrupt vector
ADDR3000    .FILL    x3000

     .END
