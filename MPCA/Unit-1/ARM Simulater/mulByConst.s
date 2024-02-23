@ Multiplication By 2^n (1,2,4,8,16,32,64.....)
MOV R1, #1
MOV R0, R1, LSL #2

@ Multiplication By 2^n + 1 (3,5,9,17..)
ADD R1,R1,R1,LSL #2

@Multiplication by 2^n-1 (3,7,15..)
MOV R2, #1
RSB R2,R2,R2,LSL #2

@Multiplication by 6
MOV R3, #1
ADD R3,R3,R3,LSL #1         ; multiply by 3
MOV R3,R3,LSL#1             ; and then by 2

@Multiply by 10 and add in extra number
MOV R4, #1
MOV R5, #3
ADD R4,R4,R4,LSL#2 ; multiply by 5
ADD R4,R5,R4,LSL#1

MOV R6 , R5,LSL#1            ; Here R5 is Not Affected