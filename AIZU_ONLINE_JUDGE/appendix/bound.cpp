#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int A[14] = {1,1,2,2,2,4,5,5,6,8,8,10,15};
    int *pos;
    int idx;

    pos = lower_bound(A,A+14,3);
    idx = distance(A,pos);
    cout << "A[" << idx << "] = " << *pos << endl;

    pos = lower_bound(A,A+14,2);
    idx = distance(A,pos);
    cout << "A[" << idx << "] = " << *pos << endl;

}

//lower_bound(先頭ポインタ,末尾ポインタ,value) valueを超える初めてのポインターが返値される