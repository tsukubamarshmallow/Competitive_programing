#include <stdio.h>

int main(void){
    int n;
    int minv,max;
    int s[200000];
    int i,j;
    
    scanf("%d",&n);
    for(i = 0; i < n ; i ++){
        scanf("%d",&s[i]);
    }

    minv = s[0];
    max = s[1] - s[0];

    for(j = 1; j < n; j++){
        if( max < s[j] - minv){
            max = s[j] - minv;
        }
        if( minv > s[j]){
            minv = s[j];
        }
        
    }

    printf("%d\n",max);
    return 0 ;
}