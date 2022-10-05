#if defined(D_NEXYS_A7)
    #include <bsp_printf.h>
    #include <bsp_mem_map.h>
    #include <bsp_version.h>
#else PRE_COMPILED_MSG("No platform defined")
#endif

#include <psp_api.h>

int main(void){
    int A[12];
    int B[12],C[12];
    uartInit();
    int size=0;
    while(size<12){
        int temp=A[size]+B[size];
        C[size]=temp<0?(-1*temp):temp;
    }
    return 0;
}