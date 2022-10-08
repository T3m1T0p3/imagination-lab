.globl main
main:


main:
    li t0, 270
    li t1, 192

    GCD:
        li t3, 0
        beq t0,t3, L1 # return b
        beq t1,t3, L2 # return a

        sub t3, t0, t1
        li t4, 0
        blt t3,t4, L3 #swap
        L4:
        rem t3, t0, t1
        mv t0, t1
        mv t1, t3
        j GCD
    L1:
        mv t3, t1
        j end
    L2:
        mv t3, t0
        j end
    L3:
        mv t4, t0
        mv t0, t1
        mv t1, t4
        j L4
end:
.end
