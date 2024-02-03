#include <stdio.h>

int linearSerch(int A[],int n,int key){
    int i = 0;
    A[n] = key;
    while( A[i] != key){
        i++;
    }
    return i != n;
}

int main(){
    int n,A[10000 + 1],q,key,sum = 0;
    
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        scanf("%d",&key);
        if(linearSerch(A,n,key) == 1){
            sum += 1;
        }
    }
    
    printf("%d\n",sum);
    
    return 0;
    
}
