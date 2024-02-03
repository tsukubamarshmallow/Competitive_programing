#include <stdio.h>

int binarySearch(int A[],int key,int n){
    int left = 0;
    int right = n;
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(A[mid] == key){
            return 1;
        }else if( key < A[mid]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return 0;
}

int main(void){
    int n,q;
    scanf("%d",&n);
    int A[1000000 + 1];
    int sum = 0;
    int key;
    
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        scanf("%d",&key);
        if(binarySearch(A,key,n)){
            sum++;
        }
    }
    
    printf("%d\n",sum);
    
    return 0;
}
