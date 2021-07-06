#include<stdio.h>
#include<stdlib.h>

#define NUM 500

typedef struct {
    int head;
    int tail;
    int vet[NUM];
}queue;

typedef struct {
    int top;
    int vetStack[NUM];
}stack;

void newQueue(queue *s);
int isEmpty(queue *s);
int isFull(queue *s);
void push(queue *s, int valor);
int pop(queue *s);
void show(queue *s);
void pushStack(stack *s, int valor); //Adiciona um valor a pilha
int popStack(stack *s); // Remove um valor da pilha
int isEmptyStack(stack *s);
void invertQueue(queue *s, stack *stack);

int main(){
    queue s;
    stack stack;
    int i=0, opc, aux;

    newQueue(&s);

    printf("\nEscolha uma das opcoes a seguir");
    printf("\n1 - Incluir novo numero na fila");
    printf("\n2 - Inverter e mostrar as duas filas");

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
                show(&s);
                invertQueue(&s, &stack);
                show(&s);
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
        printf("%i ", s -> vet[i]);
    }
    printf("\n");
}

void pushStack(stack *s, int valor){
    if (isFull(s)){
        printf("\nStack Overflow!");\
        exit(1);
    }

    s->vetStack[++s->top] = valor;
}

int popStack(stack *s){
    if (isEmpty(s)){
        printf("\nStack Underflow!");
        exit(1);
    }
    return s->vetStack[s->top--];
}

int isEmptyStack(stack *s){
    return s -> top == 0;
}

void newStack(stack *s){
    s -> top = 0;
}

void invertQueue(queue *s, stack *stack){
    newStack(stack);
    int aux;

    while(!isEmpty(s)){
        aux = pop(s);
        pushStack(stack, aux);
    }

    while(!isEmptyStack(stack)){
        aux = popStack(stack);
        push(s, aux);
    }
}