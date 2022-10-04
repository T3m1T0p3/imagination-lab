#if defined(D_NEXYS_A7)
    #include <bsp_printf.h>
    #include <bsp_mem_map.h>
    #include <bsp_version.h>
#else PRE_COMPILED_MSG("No platform defined")
#endif

#include <psp_api.h>

#define GPIO_SWs 0x80001400
#define GPIO_LEDs 0x80001404
#define GPIO_INOUT 0x80001408

#define READ_GPIO(addr) (*(volatile unsigned *)addr)
#define WRITE_GPIO(addr,val) { *(volatile unsigned *)addr=val; }

int main(void){
    int gpio_inout=0xFFFF0000;
    int switch_vals=0b0,i;
    WRITE_GPIO(GPIO_INOUT,gpio_inout);
    uartInit();
    while(1){
        for(i=16;i>0;i--){
            switch_vals=switch_vals|(0b1<<i);
            printfNexys("switch sytart:%lu",switch_vals);
        //move left->right
            while (!(switch_vals & 1)){ //while LSB!=1
                printfNexys("Moving right: %lu",switch_vals);
                WRITE_GPIO(GPIO_LEDs,switch_vals);
                switch_vals=switch_vals>>1;
            }
            WRITE_GPIO(GPIO_LEDs,switch_vals);
            while(!(switch_vals&(1<<16))){
                printfNexys("Moving left: %lu",switch_vals);
                WRITE_GPIO(GPIO_LEDs,switch_vals);
                switch_vals=switch_vals<<1;
            }
            WRITE_GPIO(GPIO_LEDs,switch_vals);
            switch_vals=0;
        }
    }
    return 0;
}