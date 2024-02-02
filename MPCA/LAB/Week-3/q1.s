.data
    a: .word 10,20
    res: .word 0
.text
    LDR r0,=a
    LDR r2,=res
    LDR r1,[r0]
    ADD r0,r0,#4
    LDR r3,[r0]
    ADD r1,r1,r3
    STR r1,[r2]
    SWI 0X11
.end