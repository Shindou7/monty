++++++++                ; Set the first cell to 8 (character 'S')
[                       ; Loop until the value at the first cell is 0
    >++++               ; Move to the second cell and add 4 to it (value becomes 4)
    [                   ; Loop until the value at the second cell is 0
        >++             ; Move to the third cell and add 2 to it (value becomes 2)
        >+++            ; Move to the fourth cell and add 3 to it (value becomes 3)
        >+++            ; Move to the fifth cell and add 3 to it (value becomes 3)
        >+              ; Move to the sixth cell and add 1 to it (value becomes 1)
        <<<<-           ; Move back to the second cell and decrement it (value becomes 3)
    ]
    >+                  ; Move to the seventh cell and add 1 to it (value becomes 1)
    >+                  ; Move to the eighth cell and add 1 to it (value becomes 1)
    >-                  ; Move to the ninth cell and subtract 1 from it (value becomes 0)
    >>+                 ; Move to the eleventh cell and add 1 to it (value becomes 1)
    [<]                 ; Move back to the tenth cell (value is 0)
    <-                  ; Decrement the tenth cell (value becomes 255)
]                       ; End of loop

>>.                     ; Move to the second cell and print the character (character 'S')
>+++++++.---.           ; Print characters 'c', 'h', 'o', and 'o'
>++++++++++.+++.        ; Print characters 'l', ' '
<++++++.++.-----.-.     ; Print characters 'm', ' ', and 'n'
>>>++.                   ; Print characters 'o' and '!'
