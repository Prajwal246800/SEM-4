@ Write a program to swap the first and last character of given string
@ Example : 
@ input : prajwal
@ Output : lrajwap

.data
A: .asciz "Prajwal\n"

.text
LDR R0, =A
SWI 0X02
MOV R1, #6
LDRB R2, [R0]
LDRB R3, [R0, R1]
STRB R3, [R0]
STRB R2, [R0, R1]
SWI 0X02
SWI 0X11
.end