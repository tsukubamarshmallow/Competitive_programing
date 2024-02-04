#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define MAX 100000
int n,k;
int T[MAX];
int number_of_luggage(long long P){
    int j = 0;
    for(int i = 0; i < k; i++){
        long long sum = 0;
        while(sum + T[j] <= P){
            sum += T[j];
            j++;
            if( j == n){
                return n;
            }
        }
    }
    return j;
}

int solve(){
    long long right = 100000*100000;//考えうる荷物の最大積載量
    long long left = 0;
    long long mid;

    while(right - left > 1){
        mid = (left + right) / 2;
        int v = number_of_luggage(mid);
        if(v >= n){
            right = mid;
        }else{
            left = mid;
        }
    } 

    return right;
}

int main(){
    int ans;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        scanf("%d",&T[i]);
    }
    ans = solve();
    cout << ans << endl;

    return 0;
}
