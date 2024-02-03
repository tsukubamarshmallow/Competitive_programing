#include <stdio.h>

int main(void){
    int n;
    int s[100];
    int i,j,k;
    scanf("%d",&n);

    for(i = 0; i < n; i++){
        scanf("%d",&s[i]);
    }

    for(k = 0; k < n; k++){
            if( k == n-1){
                printf("%d\n",s[k]);
            }else{
                printf("%d ",s[k]);
            }
    }

    for(i = 1; i < n ; i++){
        int tmp = s[i];
        j = i - 1;
        while(j >= 0 && s[j] > tmp){
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = tmp;

        for(k = 0; k < n; k++){
            if( k == n-1){
                printf("%d\n",s[k]);
            }else{
                printf("%d ",s[k]);
            }
        }
    }
    return 0;
}