#GPIO_SWs=0x80001400 GPIO_LEDs=80001404 GPIO_INOUT=80001408

.globl main
main:

main:
    li t0, 0x80001400
    li t1,0xFFFF
    sw t1, 8(t0)
L1:
    li t1, 0xffff
    li t2, 0
    L2: #while i!=0x_ffff i.e all leds not lit
        lw t2, 4(t0)
        beq t2, t1, L1

        # put on additionl bulb ging right
         li t3, 0x8000
        srli t2,t2,1
        or t2, t2, t3

        L3: #while LSB != 1
            mv t3, t2 # select LSB
            slli t3, t3, 31
            srli t3, t3, 31
            andi t3, t3, 1
            li t5, 1
            beq t3, t5, L4

            #lit LED, moving right
            sw t2, 4(t0)
            srli t2, t2, 1
            j L3
        L4:
        # switch on additional led when goin left  
        slli t3, t2, 1 //position of LED to switch
        or t2, t2, t3

        #while 16th bit!= 1 lit leds moving left
        L5:
            mv t3, t2
            slli t3, t3, 16
            srli t3, t3, 31

            andi t3, t3, 1
            li t4, 1
            beq t3, t4, L6
            slli t2, t2, 1
            sw t2, 4(t0)
            j L5
        L6:
            sw t2, 4(t0)
            j L2
.end




