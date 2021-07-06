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
void contar(queue *s);

int main(){
    queue s;
    int i=0, opc, aux;

    newQueue(&s);

    printf("\nEscolha uma das opcoes a seguir");
    printf("\n1 - Incluir novo numero na fila");
    printf("\n2 - Mostrar fila");

    do{
        printf("\n\nInsira a opcao: ");
        scanf("%i", &opc);

        switch(opc){
            case 1:
                printf("Insira um valora fila: ");
                scanf("%i", &aux);
                push(&s, aux);
                break;
            case 2:
                contar(&s);
                i++;
                break;
            default:
                printf("\nOpcao incorreta!");
                break;
        }
    }while(i == 0);

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
    return s -> tail - s -> head == NUM;
}

void push(queue *s, int valor){
    if (isFull(s)){
        printf("\nQueue Overflow!");\
        exit(1);
    }

    s->vet[s->tail++ % NUM] = valor;
}

int pop(queue *s){
    if (isEmpty(s)){
        printf("\nQueue Underflow!");
        exit(1);
    }

    return s->vet[s->head++ % NUM];
}

void show(queue *s){
    int i;
    printf("Fila: ");
    for(i = s -> head;i < s -> tail; i++){
        printf("%i", s -> vet[i % NUM]);
    }
    printf("\n");
}

void contar(queue *s){
    int i, aux=0;

    for(i = s -> head;i < s -> tail; i++){
        aux++;
    }

    printf("\nA fila possui %i elementos", aux);
}