# GPIO_SWs=0x80001400
.globl main
main:

main:

    li t0, 0x80001400
    li t1, 0xFFFF0000
    sw t1, 8(t0)

    lw t1, 0(t0)
    mv t2, t1
    slli t1, t1, 12
    srli t2,t2, 12
    slli t2, t2, 12
    add t1, t1, t2
    sw t1, 4(t0)
.end