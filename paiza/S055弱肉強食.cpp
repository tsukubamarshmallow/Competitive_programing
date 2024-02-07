#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

int conv(char c) {
    switch(c) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        case 'i':
            return 8;
        case 'j':
            return 9;
        case 'k':
            return 10;
        case 'l':
            return 11;
        case 'm':
            return 12;
        case 'n':
            return 13;
        case 'o':
            return 14;
        case 'p':
            return 15;
        case 'q':
            return 16;
        case 'r':
            return 17;
        case 's':
            return 18;
        case 't':
            return 19;
        case 'u':
            return 20;
        case 'v':
            return 21;
        case 'w':
            return 22;
        case 'x':
            return 23;
        case 'y':
            return 24;
        case 'z':
            return 25;
        default:
            return -1;
    }
}

char reverseConv(int n) {
    switch(n) {
        case 0:
            return 'a';
        case 1:
            return 'b';
        case 2:
            return 'c';
        case 3:
            return 'd';
        case 4:
            return 'e';
        case 5:
            return 'f';
        case 6:
            return 'g';
        case 7:
            return 'h';
        case 8:
            return 'i';
        case 9:
            return 'j';
        case 10:
            return 'k';
        case 11:
            return 'l';
        case 12:
            return 'm';
        case 13:
            return 'n';
        case 14:
            return 'o';
        case 15:
            return 'p';
        case 16:
            return 'q';
        case 17:
            return 'r';
        case 18:
            return 's';
        case 19:
            return 't';
        case 20:
            return 'u';
        case 21:
            return 'v';
        case 22:
            return 'w';
        case 23:
            return 'x';
        case 24:
            return 'y';
        case 25:
            return 'z';
        default:
            // エラー処理やデフォルトの返り値を設定することができます
            // 例えば、エラーの場合は空白文字を返すなど
            return ' ';
    }
}

void rec(int v, const Graph &G, vector<bool> &seen, vector<int> &order) {
    seen[v] = true;
    for (auto next : G[v]) {
        if (seen[next]) continue; // 既に訪問済みなら探索しない
        rec(next, G, seen, order);
    }
    order.push_back(v);
}

int main(void){
    int H,W;
    char A[100][100];
    cin >> H >> W;
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
        }
    }
    
    int N;
    cin >> N;
    
    Graph G(26);
    for(int i = 0; i < N; i++){
        char a,b;
        cin >> a >> b;
        G[conv(a)].push_back(conv(b));
    }
    
    // 探索
    vector<bool> seen(N, 0);
    vector<int> order; 
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; 
        rec(v, G, seen, order);
    }
    reverse(order.begin(), order.end());

    // 出力
    for (auto v : order) {
        for (auto w : G[v]) {
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (A[i][j] == reverseConv(v)) {
                        for (int ni = -1; ni <= 1; ni++) {
                            for (int nj = -1; nj <= 1; nj++) {
                                int ni_idx = i + ni;
                                int nj_idx = j + nj;
    
                                // Check if the indices are within the valid range
                                if (ni_idx >= 0 && ni_idx < H && nj_idx >= 0 && nj_idx < W) {
                                    if (A[ni_idx][nj_idx] == reverseConv(w)) {
                                        A[ni_idx][nj_idx] = '-';
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j< W; j++){
            if(j == 0){
                cout << A[i][j];
            }else{
                cout << ' ' << A[i][j];
            }
        }
        cout << endl;
    }
    
    
    return 0;
}