,>,        ; Read two digits from stdin

>++++++    ; Convert ASCII '0' to 6

[           ; Convert ASCII digit to integer (1st digit)
	>++++++++
	<-
]

>>++++++   ; Convert ASCII '0' to 6 (reset)

[           ; Convert ASCII digit to integer (2nd digit)
	>++++++++
	<-
]

>           ; Move to the 3rd cell (result)

[           ; Multiply loop
	-       ; Decrement 2nd cell (iterator)
	<<<<-   ; Move back to 2nd cell

	<-      ; Move back to 1st cell (2nd input digit)
	>>>>>   ; Move to the 4th cell (temporary storage)

	>       ; Move to the 5th cell

	[       ; Inner loop: Multiply and accumulate
		>+  ; Increment 4th cell (product)
		>>+ ; Increment 5th cell (iterator)
		<<<-; Move back to 3rd cell
	]

	>>>     ; Move to the 6th cell (temporary storage)

	[       ; Inner loop: Accumulate result
		-   ; Decrement 5th cell (iterator)
		<<<+; Increment 6th cell (result)
		>>> ; Move back to 5th cell
	]

	<<<<-   ; Move back to 2nd cell (iterator)
]

>>          ; Move to the 7th cell (result)

[           ; Convert integer result to ASCII for printing
	-       ; Decrement 7th cell (ASCII offset)
	>+      ; Increment 8th cell (result)
	<       ; Move back to 7th cell
]

.           ; Print result as ASCII character

>++++++    ; Convert ASCII '0' to 6 (reset)
[           ; Convert result to integer
	<++++++;-; Convert ASCII '0' to 6
	>++++   ; Decrement 8th cell (iterator)
	<       ; Move back to 8th cell (result)
]

>>.         ; Print result followed by new line
