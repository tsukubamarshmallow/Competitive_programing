#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node{
    int key;
    Node *next,*prev;
};

Node *nil;

void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil ->next = nil;
    nil -> prev = nil;
}

void insert(int key){
    Node *x = (Node *)malloc(sizeof(Node));
    x -> key = key;
    x -> next = nil -> next;
    nil -> next -> prev = x;
    nil -> next = x;
    x -> prev = nil;
}

Node* listSearch(int key){
    Node *cur = nil -> next;
    while(cur != nil && cur -> key != key){
        cur = cur -> next;
    }
    return cur;
}

void deleteNode(Node *t){
    if( t != nil){
        t -> next -> prev = t -> prev;
        t -> prev -> next = t -> next;
        free(t);
    }
}

void deleteFirst(){
    deleteNode(nil -> next);
}

void deleteLast(){
    deleteNode(nil -> prev);
}

void deleteKey(int key){
    deleteNode(listSearch(key));
}

void printList(){
    Node* cur = nil -> next;
    int isf = 0;
    while(cur != nil){
        if(isf++ > 0){
            printf(" ");
        }
        printf("%d",cur->key);
        cur = cur-> next;
    }
    printf("\n");
}

int main(void){
    int key,n,i;
    char com[20];

    scanf("%d",&n);
    init();

    for(i = 0; i < n; i ++){
        scanf("%s",com);
        scanf("%d",&key);
        if(com[0] == 'i'){
            insert(key);
        }else if(com[0] == 'd'){
            if(strlen(com) > 6){
                if(com[6] == 'F'){
                    deleteFirst();
                }else if(com[6] = 'L'){
                    deleteLast();
                }
            }else{
                deleteKey(key);
            }
        }
    }

    printList();

    return 0;


}