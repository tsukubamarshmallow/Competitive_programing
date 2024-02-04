#include<iostream>
using namespace std;
void merge(int A[],int left,int mid,int right){
    n1 = mid - left;
    n2 = right - mid;
    //L[0,1,2,...n1]とR[0,1,2,...n2]を生成
    for(int i = 0, i < n1; i++){
        L[i] = A[left + 1];
    }

    for(int i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
}