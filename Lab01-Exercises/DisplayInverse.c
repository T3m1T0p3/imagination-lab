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
    int switch_vals;
    WRITE_GPIO(GPIO_INOUT,gpio_inout);
    uartInit();
    while(1){
        switch_vals=READ_GPIO(GPIO_SWs);
        switch_vals= ~switch_vals;
        switch_vals=switch_vals>>16;
        WRITE_GPIO(GPIO_LEDs,switch_vals);
    }
    return 0;
}