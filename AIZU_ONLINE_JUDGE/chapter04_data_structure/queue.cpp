#include <stdio.h>
#include <string.h>
#define LEN 100005

typedef struct pp{
    char name[100];
    int t;
} P;

P Q[LEN];
int head,tail,n;

void initialize(){
    head = tail = 0;
}

bool isEmpty(){
    if(head == tail){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if(head == (tail + 1) % LEN){
        return true;
    }else{
        return false;
    }
}

void enqueue(P p){
    if(!isFull()){
        Q[tail] = p;
        if(tail + 1 == LEN){
            tail = 0;
        }else{
            tail++;
        }
    }
}

P dequeue(){
    if(!isEmpty()){
        P p = Q[head];
        if(head + 1 == LEN){
            head = 0;
        }else{
            head++;
        }
        return p;
    }
}

int min(int a, int b){
    return a < b ? a : b;
}

int main(){
    int elaps = 0,c;
    int i,q;
    P u;
    scanf("%d %d",&n,&q);

    for(i = 1; i <= n; i++){
        scanf("%s",Q[i].name);
        scanf("%d",&Q[i].t);
    }

    head = 1;
    tail = n + 1;

    while(!isEmpty()){
        u = dequeue();
        c = min(q,u.t);
        u.t -= c;
        elaps += c;
        if(u.t > 0){
            enqueue(u);
        }else{
            printf("%s %d\n",u.name,elaps);
        }
    }

    return 0;


}
