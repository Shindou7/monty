,>,            ; Read two digits from stdin (ASCII values)

>++++++        ; Convert ASCII '0' to 6 in the second cell

[               ; Convert ASCII digit to integer (first digit)
	>++++++++   ; Convert ASCII '0' to 8
	<-          ; Move back to input cell
]

>>++++++       ; Convert ASCII '0' to 6 in the second cell (reset)

[               ; Convert ASCII digit to integer (second digit)
	>++++++++   ; Convert ASCII '0' to 8
	<-          ; Move back to input cell
]

>               ; Move to the third cell (result)

[               ; Multiply loop
	-           ; Decrement the second cell (iterator)
	<<<<-       ; Move back to the second cell

	<-          ; Move back to the first cell (second input digit)
	>>>>>       ; Move to the fourth cell (temporary storage)

	>           ; Move to the fifth cell

	[           ; Inner loop: Multiply and accumulate
		>+      ; Increment fourth cell (product)
		>>+     ; Increment fifth cell (iterator)
		<<<-    ; Move back to third cell
	]           ; End of inner loop

	>>>         ; Move to the sixth cell (temporary storage)

	[           ; Inner loop: Accumulate result
		-       ; Decrement fifth cell (iterator)
		<<<+    ; Increment sixth cell (result)
		>>>     ; Move back to fifth cell
	]           ; End of inner loop

	<<<<-       ; Move back to second cell (iterator)
]

>>              ; Move to the seventh cell (result)

[               ; Convert integer result to ASCII for printing
	-           ; Decrement seventh cell (ASCII offset)
	>+          ; Increment eighth cell (result)
	<           ; Move back to seventh cell
]

>.              ; Print the result as an ASCII character
