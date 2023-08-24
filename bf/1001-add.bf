,           ; Read the first digit from stdin
[-          ; Start loop to convert ASCII to integer
    >-      ; Decrement the first cell (subtract ASCII value of '0')
    <       ; Move back to the input cell
]           ; End loop

,           ; Read the second digit from stdin
[-          ; Start loop to convert ASCII to integer
    >-      ; Decrement the second cell (subtract ASCII value of '0')
    <       ; Move back to the input cell
]           ; End loop

+           ; Add the first and second digits

[           ; Start loop to convert integer to ASCII
    >+      ; Increment the first cell (add ASCII value of '0')
    <-      ; Move back to the result cell
]           ; End loop

.           ; Print the result as an ASCII character
