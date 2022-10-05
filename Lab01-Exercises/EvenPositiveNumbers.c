#if defined(D_NEXYS_A7)
    #include <bsp_printf.h>
    #include <bsp_mem_map.h>
    #include <bsp_version.h>
#else PRE_COMPILED_MSG("No platform defined")
#endif

#include <psp_api.h>

/*typedef struct Node{
    int val;
    struct Node* next;
} Node;

//typedef ListNode Node; 

Node* B(int* A,int size){
    Node *head;
    Node res;
    res.next=NULL;
    head=&res;
    while(--size>0){
        int temp=*A;
        if(temp%2==0 && temp>0){
            Node n;
            n.val=0;
            n.next=NULL;
            res.val=temp;
            res.next=&n;
            printfNexys("A[%d]=%d",size,head->val);
            res=*(res.next);
            
        }
        A+=1;
    }
    return head;
}*/

void B(int* A,int* b,int size){
    int i=0;
    while((i++<size)){
        int temp=*A;
        if(temp%2==0 && temp>0){
            *b=temp;
            b+=1;
        }
        A+=1;
    }
    return;
}
int main(void){
    int A[12]={0,1,2,7,-8,4,5,12,11,-2,6,3};
    int b[12];
    uartInit();
    B(A,b,12);
    int size=0;
    while(b[size]>0){
        size++;
    }
    printfNexys("Number of elements in B = %d",size);
    return 0;
}