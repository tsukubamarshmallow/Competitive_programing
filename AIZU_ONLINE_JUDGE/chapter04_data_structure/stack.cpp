#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int S[200];
int top;

void initialize(){
    top = 0;
}

int isEmpty(){
    if(top == 0){
        return 1;
    }else{
        return 0;
    }
}

int isFull(){
    if(top >= 199){
        return 1;
    }else{
        return 0;
    }
}

void push(int x){
    if(isFull() == 0){
        S[++top] = x;
    }
}

int pop(){
    if(isEmpty() == 0){
        top--;
        return S[top + 1];
    }
}

int main(void){
    top = 0;
    char s[100];
    int a,b;

    while(scanf("%s",s) != EOF){
        if(s[0] == '+'){
            a = pop();
            b = pop();
            push(a+b);
        }else if( s[0] == '-'){
            a = pop();
            b = pop();
            push(b-a);
        }else if(s[0] == '*'){
            a = pop();
            b = pop();
            push(a*b);
        }else{
            push(atoi(s));
        }
    }
    printf("%d\n",pop());
}