#if defined(D_NEXYS_A7)
    #include <bsp_printf.h>
    #include <bsp_mem_map.h>
    #include <bsp_version.h>
#else PRE_COMPILED_MSG("No platform defined")
#endif

#include <psp_api.h>

int main(void){
    int A[12]={0,1,2,7,-8,4,5,12,11,-2,6,3};
    uartInit();
    int x,y;
    for(int i=0;i<12;i++){
        for(int t=0;t<12;t++){
            x=A[t];
            for(int j=i+1;j<12;j++){
                y=A[j];
                if(y<x){
                    A[t]=y;
                    A[j]=x;
                    break;
                }
            }
        }
    }
    for(int k=0;k<12;k++){
        printfNexys("%d",A[k]);
    }
    return 0;
}