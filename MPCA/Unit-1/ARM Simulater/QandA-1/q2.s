@ Convert the following assignment into ARM.
    @ F = ( G + H ) – ( I + J ).
    @ use the register R0 to R4 as operands  F to J respectively.

@ Note: User different addressing modes both at source & destination operand positions.

MOV R1, #1      @ G = 1
MOV R2, #2      @ H = 2
MOV R3, #3      @ I = 3
MOV R4, #4      @ J = 4
ADD R5, R1, R2  @ temporary register R5 = G + H; R5 = 1 + 2; R5 = 3;
ADD R6, R3, R4  @ temporary register R6 = I + J; R6 = 3 + 4; R6 = 7;
SUB R0, R5,R6   @ R0 = (G + H) - (I + J); R0 = 3 - 7; R0 = -4;