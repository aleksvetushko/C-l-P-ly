.ORIG x3500

      LDI R0, KBDR
      LD R3, ZERO
      STI R3, KBSR ; clear KBSR
      LDI R5, EOUP1 ; load value at address in x32FF into R5
      STR R5, R6, #0

      RTI ; top 2 elements on supervisor stack loaded into PC, PSR

      HALT

KBDR  .FILL xFE02 ; address of KBDR
KBSR  .FILL xFE00 ; address of KBSR
ZERO  .FILL x0000 ; zero value to clear KBSR
EOUP1 .FILL x32FF ; address of end of UP1

      .END
