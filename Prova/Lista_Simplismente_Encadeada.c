#include<stdio.h>
#include<stdlib.h>

typedef struct NodeItem {
  int info;
  struct NodeItem *prox;
} node;

typedef struct {
  node *first;
} list;

list *newList();
node *addNode(list *l, int value);
node *findNode(list *l, int value);
void delNode(list *l, int value);
int isEmpty(list *l);
int length(list *l);
void showList(list *l);

int main(){
    list *l;
    l = newList();

    return 0;
}

list *newList(){
    list *l = (node *)malloc(sizeof(node));
    l -> first = NULL;
    return l;
}

node *addNode(list *l, int value){
    node *n = (node *)malloc(sizeof(node));
    n -> info = value;
    n -> prox = l -> first;
    l -> first = n;
    return n;
}

node *findNode(list *l, int value){
    node *n = l -> first;
    while(n != NULL && n -> info != value){
        n = n -> prox;
    }
    return n;
}

void delNode(list *l, int value){
    node *n, *prev;
    n = findNode(l, value);
    if(n != NULL){
        if(n == l -> first){
            l -> first = n -> prox;
        }else{
            prev = l -> first;
            while (prev -> prox != n){
                prev = prev -> prox;
            }
            prev -> prox = n -> prox;
        }
        free(n);
    }
}

void showList(list *l){
    node *n;
    if(isEmpty(l)){
        printf("\nA lista está vazia");
    }else{
        printf("\nA lista possui %i elemento(s), sendo: ",length(l));
        n = l -> first;
        while (n != NULL){
            printf("%i, ", n -> info);
            n = n -> prox;
        }        
    }
}

int length(list *l) {
  int i=0;
  node *n = l->first;
  while(n != NULL) {
    n = n->prox;
    i++;
  }
  return i;
}

int isEmpty(list *l) {
  return l->first == NULL;
}