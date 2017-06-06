.ORIG x3300

      STI R7, PCADD ; store R6 (PC) into a memory address
      LD R4, ENABLE
      STI R4, KBSR; turn on interrupt enable bit
      LD R4, UP2
      JMP R4 ; jump to UP2

      HALT

PCADD    .FILL x32FF ; address to which PC should be stored
KBSR     .FILL xFE00 ; KBSR address
ENABLE   .FILL x4000 ; 14th bit is 1, rest are 0
UP2      .FILL x3400 ; start address of UP2

      .END
