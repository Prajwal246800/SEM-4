.data
name: .asciz "Vamshi"
.text
ldr r0,=name
mov r1,#0
l1:
    ldrb r2,[r0],#1
    cmp r2,#0
    beq endd
    add r1,r1,#1
    b l1
endd:
    ldr r0,=name
    swi 0x02
    swi 0x11
.end