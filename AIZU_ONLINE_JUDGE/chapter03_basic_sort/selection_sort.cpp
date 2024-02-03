#include <stdio.h>

void scanArray(int a[], int n){
    int i;
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
}

void printArray(const int a[], int n){
    int i;
    for(i = 0; i < n; i++){
        if(i != n-1){
            printf("%d ",a[i]);
        }else{
            printf("%d\n",a[i]);
        }
    }
}

void swap(int*a, int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int selectionSort(int a[], int n){
    int i,j;
    int minj;
    int count = 0;

    for(i = 0; i < n - 1; i++){
        minj = i;
        for(j = i + 1; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if( i != minj){
            swap(&a[i],&a[minj]);
            count++;
        }
    }

    return count;
}

int main(void){
    int n;
    int s[100];
    int sum;

    scanf("%d",&n);
    scanArray(s,n);
    sum = selectionSort(s,n);
    printArray(s,n);
    printf("%d\n",sum);
    return 0;
}