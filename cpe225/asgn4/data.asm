; Aleks Vetushko
; Ashish Sethi
; asgn3

         .ORIG x3300

Q1       .STRINGZ "\nHow often do you watch the news?\n   1 - I don't watch the news\n   2 - 1-2 times per week\n   3 - 3-5 times per week\n   4 - I watch the news ALL THE TIME\n"
Q1Answ   .FILL #6
         .FILL #0
         .FILL #2
         .FILL #4

Q2       .STRINGZ "\nHow often do you consume alcohol?\n   1 - Never\n   2 - I drank once, hated the taste\n   3 - Regularly\n   4 - I'm drunk right now\n"
Q2Answ   .FILL #2
	      .FILL #4
	      .FILL #6
	      .FILL #0

Q3       .STRINGZ "\nCan a person be motivated by desires that are not ultimately selfish?\n   1 - yes\n   2 - no\n   3 - They can\n   4 - They cannot\n"
Q3Answ   .FILL #6
	      .FILL #0
	      .FILL #4
	      .FILL #2

Result1  .STRINGZ "\nNice"
Result2  .STRINGZ "\nCool"
Result3  .STRINGZ "\nNo"
Result4  .STRINGZ "\ntHere tHey gHo"

	      .END
