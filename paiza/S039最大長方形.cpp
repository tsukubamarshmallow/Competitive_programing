#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>
#define MAX 1400

using namespace std;

struct retangle{
    int height,pos;
};

int getLargest(int size,int buffer[]){
    stack<retangle> S;
    int maxv = 0;
    buffer[size] = 0;
    
    for(int i = 0; i <= size; i++){
        retangle rec;
        rec.height = buffer[i];
        rec.pos = i;
        if(S.empty()){
            S.push(rec);
        }else{
            if(S.top().height < rec.height){
                S.push(rec);
            }else if(S.top().height > rec.height){
                int target = i;
                while(!S.empty() && S.top().height >= rec.height){
                    retangle p = S.top();
                    S.pop();
                    int area = p.height + (i - p.pos);
                    maxv = max(maxv,area);
                    target = p.pos;
                }
                rec.pos = target;
                S.push(rec);
            }
        }
    }
    return maxv;
}

int H,W;
int buffer[MAX][MAX];
int T[MAX][MAX];

int getLargest(){
    for(int j = 0; j < W; j++){
        for(int i = 0; i < H; i++){
            if(buffer[i][j]){
                T[i][j] = 0;
            }else{
                T[i][j] = (i > 0) ? T[i - 1][j] + 1 : 1;
            }
        }
    }
    
    int maxv = 0;
    for(int i = 0; i < H; i++){
        maxv = max(maxv,getLargest(W,T[i]));
    }
    
    return maxv;
}



int main(void){
    cin >> H >> W;
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char c;
            cin >> c;
            if(c == '.'){
                buffer[i][j] = 0;
            }else{
                buffer[i][j] = 1;
            }
        }
    }    
    cout << getLargest() << endl;
    
    return 0;
}