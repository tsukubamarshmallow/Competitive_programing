#include <iostream>
using namespace std;

int partition(int A[],int p,int r){
    int x = A[r];
    int i = p - 1;

    for(int j = p; j < r; j++){
        if(A[j] <= x){
            i++;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    int tmp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = tmp;
    return i + 1;

}
int main(){
    int N;
    int A[100000];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int q = partition(A,0,N);

    for(int i = 0; i < N; i++){
        if(i == q){
            cout << ' ' << '[' << A[i] << ']';
        }else if(i == 0){
            cout << A[i];
        }else{
            cout << ' ' << A[i];
        }
    }
    cout << endl;
}