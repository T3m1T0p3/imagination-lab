#if defined(D_NEXYS_A7)
    #include <bsp_printf.h>
    #include <bsp_mem_map.h>
    #include <bsp_version.h>
#else PRE_COMPILED_MSG("No platform defined")
#endif

#include <psp_api.h>


int main(void){
    static int n=7;
    long fac=1;
    uartInit();  
    int v[12];
    for(int i=1;i<=n;i++){
        fac*=i;
    }
    printfNexys("factorial(%d) = %d",n,fac);
    return 0;
}