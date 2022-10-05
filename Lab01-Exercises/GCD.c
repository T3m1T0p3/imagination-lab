#if defined(D_NEXYS_A7)
    #include <bsp_printf.h>
    #include <bsp_mem_map.h>
    #include <bsp_version.h>
#else PRE_COMPILED_MSG("No platform defined")
#endif

#include <psp_api.h>


int GCD(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a<b){
        int temp=a;
        a=b;
        b=temp;
    }
    int rem=a%b;
    return GCD(b,rem);
}

int main(void){

    uartInit();  
    static int a=270,b=192;
    int gcd=GCD(a,b);
    
    printfNexys("GCD %d",gcd);  
    return 0;
}