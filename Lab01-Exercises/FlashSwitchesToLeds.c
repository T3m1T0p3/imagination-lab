#if defined(D_NEXYS_A7)
    #include <bsp_printf.h>
    #include <bsp_mem_map.h>
    #include <bsp_version.h>
#else   PRE_COMPILED_MSG("possible missing headers")
#endif
#include <psp_api.h>

#define GPIO_SWs 0x80001400
#define GPIO_LEDs 0x80001404
#define GPIO_INOUT 0x80001408
#define DELAY 1000000
#define READ_GPIO(addr) (*(volatile unsigned *)addr)
#define WRITE_GPIO(addr,val) { (*(volatile unsigned *)addr)=val; }
int main(void){
    int switch_vals;
    int gpio=0xFFFF0000; //MS 16B==inputs LS16B==outputs
    WRITE_GPIO(GPIO_INOUT,gpio);
    uartInit();
    while(1){
        int temp=READ_GPIO(GPIO_INOUT);
        temp=temp>>16;
        WRITE_GPIO(GPIO_SWs,temp);
        switch_vals=READ_GPIO(GPIO_SWs);
        switch_vals=switch_vals>>16;
        WRITE_GPIO(GPIO_LEDs,switch_vals);
        for(int i=0;i<DELAY;i++);
        printfNexys("switch value: %d",switch_vals);
    }

    return 0;
}