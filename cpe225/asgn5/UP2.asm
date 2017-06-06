.ORIG x3400

      LD R0, STAR ; load * into R0
      AND R2, R2, #0 ; clear R2

LOOP1 ADD R2, R2, #1 ; increment R2
      BRzp LOOP1 ; go back to loop if R2 isn't negative
      OUT ; print R0, AKA *, to console
      AND R2, R2, #0 ; clear R2
      BRnzp LOOP1 ; go back to loop unconditionally

      HALT

STAR  .FILL    x2A ; *

      .END
