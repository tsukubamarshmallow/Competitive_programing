#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAX 2000

int n,q;
int T[MAX];
int M[MAX];

int solve(int i, int m){
    if(m == 0){
        return 1;
    }
    if(i >= n){
        return 0;
    }
    int ans = solve(i+1,m) || solve(i+1,m-T[i]);
    return ans;
}
int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> T[i] ;
    }
    
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> M[i] ;
    }
    
    for(int i = 0; i < q; i++){
        if(solve(0,M[i]) == 1){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    
    return 0;
}