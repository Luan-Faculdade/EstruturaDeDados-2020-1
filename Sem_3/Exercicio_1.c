#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define NUM 15
#define NAME 500

typedef struct {
    int head;
    int tail;
    int vet[NUM];
}queue;

struct cliente{
    char name[NAME];
}client[NUM];

void newQueue(queue *s);
int isEmpty(queue *s);
int isFull(queue *s);
void push(queue *s, int valor);
int pop(queue *s);
void show(queue *s, int cliente);

int main(){
    queue s;
    //struct cliente client[NUM];
    int opc, i=0, len, k, numClient=0, proxClient=0;

    newQueue(&s);

    printf("\nEscolha uma das opcoes a seguir");
    printf("\n1 - Incluir nova pessoa na fila");
    printf("\n2 - Atender pessoa");

    do{
        printf("\n\nInsira a opcao: ");
        scanf("%i", &opc);

        switch(opc){
            case 1:
                printf("\nInsira o nome do usuario: ");
                scanf(" %[^\n]", client[numClient].name);
                //len = strlen(name);
                push(&s, numClient);
                numClient++;
                break;
            case 2:
                pop(&s);
                show(&s, proxClient);
                proxClient = s.head;
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

void show(queue *s, int cliente){
    int i;
    srand(time(NULL));
    int caixa = rand() % 6;

    printf("\nPor favor, cliente %s, dirija-se ao caixa %i\n", client[cliente].name, caixa);
}