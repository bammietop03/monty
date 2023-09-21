,          ; Read the first digit and store it in the first cell
[          ; Start a loop
  -        ; Subtract 1 from the first cell to clear it
  >+       ; Add 1 to the second cell
  <        ; Move back to the first cell
]          ; End the loop when the first cell becomes 0

>>>        ; Move to the third cell
[          ; Start a loop
  -        ; Subtract 1 from the third cell to clear it
  >+       ; Add 1 to the fourth cell
  <        ; Move back to the third cell
]          ; End the loop when the third cell becomes 0

<          ; Move back to the second cell
[->+<]     ; Add the value of the second cell to the first cell
>          ; Move to the fourth cell
[-<+>]     ; Add the value of the fourth cell to the first cell
.          ; Output the result as a character
