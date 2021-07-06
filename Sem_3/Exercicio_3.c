#include<stdio.h>
#include<stdlib.h>

#define NUM 500

typedef struct {
    int head;
    int tail;
    char vet[NUM];
}queue;

typedef struct {
    int top;
    char vetStack[NUM];
    int pos[NUM];
}stack;

void newQueue(queue *s);
int isEmpty(queue *s);
int isFull(queue *s);
void push(queue *s, char valor);
char pop(queue *s);
void show(queue *s);
void pushStack(stack *s, char valor, int valor2);
int popStack(stack *s);
int isEmptyStack(stack *s);
void invertQueue(queue *s, stack *stack);
void saveStack(queue *s, stack *stck, char aux);

int main(){
    queue s;
    stack stack;
    int i=0, opc;
    char aux;

    newQueue(&s);
    newStack(&stack);

    printf("\nEscolha uma das opcoes a seguir");
    printf("\n1 - Incluir novo numero na fila");
    printf("\n2 - Inverter e mostrar as duas filas");

    do{
        printf("\n\nInsira a opcao: ");
        scanf("%i", &opc);

        switch(opc){
            case 1:
                printf("Insira um valora fila: ");
                scanf("%s", &aux);
                saveStack(&s, &stack, aux);                
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

void push(queue *s, char valor){
    if (isFull(s)){
        printf("\nQueue Overflow!");\
        exit(1);
    }

    s->vet[s->tail++] = valor;
}

char pop(queue *s){
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
        printf("%c ", s -> vet[i]);
    }
    printf("\n");
}

void pushStack(stack *s, char valor, int valor2){
    if (isFull(s)){
        printf("\nStack Overflow!");\
        exit(1);
    }
    s->pos[s->top] = valor2;
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
    int base = s-> tail;
    int aux, i, k=stack->top, j=0;

    for(i=0; i < base; i++){
       if(i == stack->pos[k]){
           s->vet[i] = stack->vetStack[k];
           j++;
           k--;
       }
    }
    
}

void saveStack(queue *s, stack *stck, char aux){
    
    if(aux == '1' || aux == '2' || aux == '3' || aux == '4' || aux == '5' || aux == '6' || aux == '7' || aux == '8' || aux == '9'){
        pushStack(stck, aux, s->tail);
    }
}