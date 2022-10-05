# GPIO_SWs=t0, GPIO_LEDs=t0+4, GPIO_INOUT=t0+8

.globl main
main:


main:
    li t0,0x80001400
    li t1, 0xFFFF0000

    sw t1, 8(t0)

L1:
    lw t1, 0(t0)
    srli t1,t1,16
    sw t1,4(t0)
    li t2,0
    li t3, 1000000
    L2:
        bge t2, t3, L1
        addi t2,t2,1
        j L2
