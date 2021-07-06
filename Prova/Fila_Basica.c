#include<stdio.h>
#include<stdlib.h>

#define NUM 500

typedef struct {
    int head;
    int tail;
    int vet[NUM];
}queue;

void newQueue(queue *s);
int isEmpty(queue *s);
int isFull(queue *s);
void push(queue *s, int valor);
int pop(queue *s);
void show(queue *s);

int main(){
    queue s;
    newQueue(&s);
    return 0;
}

void newQueue(queue *s){
    s -> head = 0;
    s ->tail = 0;
}

int isEmpty(queue *s){
    return s -> head == s -> tail;
}

int isFull(queue *s){
    return s -> tail == NUM;
}

void push(queue *s, int valor){
    if (isFull(s)){
        printf("\nQueue Overflow!");\
        exit(1);
    }

    s->vet[s->tail++] = valor;
}

int pop(queue *s){
    if (isEmpty(s)){
        printf("\nQueue Underflow!");
        exit(1);
    }

    return s->vet[s->head++];
}

void show(queue *s){
    int i;
    printf("Fila: ");
    for(i = s -> head;i < s -> tail; i++){
        printf("%i", s -> vet[i]);
    }
    printf("\n");
}