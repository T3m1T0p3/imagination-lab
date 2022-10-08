# GPIO_SWs=0x80001400, GPIO_LEDs=80001404

.globl main
main:

main:
    li t0,0x80001400
    li t1,0xFFFF

    sw t1,8(t0)

L1:
    sw t1, 0(t0)
    not t1, t1
    srli t1,t1,16
    sw t1, 4(t0)
    li t2, 0
    li t3, 1000000
    L2:
    bge t2,t3,L1
    addi t2, t2, 1
    j L2

.end