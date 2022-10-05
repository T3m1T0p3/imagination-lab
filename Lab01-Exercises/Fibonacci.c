#if defined(D_NEXYS_A7)
    #include <bsp_printf.h>
    #include <bsp_mem_map.h>
    #include <bsp_version.h>
#else PRE_COMPILED_MSG("No platform defined")
#endif

#include <psp_api.h>


int FIB(int n){
    if(n<=1) return n;
    return FIB(n-1) + FIB(n-2);
}

int main(void){

    uartInit();  
    int v[12];
    for(int i=0;i<13;i++){
        int num=FIB(i);
        printfNexys("fib(%d) = %d",i,num);
        v[(i-1)]=num; 
    } 
    return 0;
}