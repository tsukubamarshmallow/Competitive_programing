#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    vector<int>::iterator it;
    for( it = v.begin(); it != v.end(); it++){
        cout << *it;
    }
    cout << endl;
}

int main(){
    int N = 4;
    vector<int> v;

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        v.push_Back(x);
    }

    print(v);

    vector<int>::iterator it = v.begin();
    *it = 3;
    it++;
    (*it)++;

    print(v);

    return 0;
}

//イテレーターは様々なデータコンテナに対するポインタと考えることが出来る。
//begin()で先頭要素を取得することが出来,end()で末尾要素を取得することが出来る。