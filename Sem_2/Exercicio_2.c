#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Codigo por Luan Emanuel, RA 2143860.

typedef struct NodeItem{
    char msg;
    struct NodeItem *px;
}node;

typedef struct{
    node *top;
}stack;

void newStack(stack *p); //Gera nova pilha
char top(stack *p); //Topo da pilha
void push(stack *p, char valor); //Inseri valor na pilha
char pop(stack *p); //Retira e retorna valor da pilha
int isEmpty(stack *p); //Indica se a pilha esta vazia
node *newNode(char valor); //Gera um novo no
int checkDiamonds(char c[], int len); //Verifica se a quantidade de diamantes

int main(){
    stack s;
    char seq[100];
    int len;
    printf("Insira o que o joao encontrou: ");
    scanf(" %[^\n]", &seq);
    len = strlen(seq);

    printf("\nJoao encontrou %i diamantes", checkDiamonds(seq, len));
    return 0;
}

node *newNode(char valor){
    node *nd = (node *)malloc(sizeof(node));
    nd -> msg = valor;
    nd -> px = NULL;
    return nd;
}

void newStack(stack *p){
    p -> top = NULL;
}

int isEmpty(stack *p){
    return p -> top == NULL;
}

char top(stack *p){
    if(isEmpty(p)){
        printf("Error: STACK UNDERFLOW");
        exit(0);
    }else{
        return p -> top -> msg;
    }
}

void push(stack *p, char valor){
    node *nd = newNode(valor);
    nd -> px = p -> top;
    p -> top = nd;
}

char pop(stack *p){
    node *n;
    char i;
    i = top(p);
    p -> top = n -> px;
    free(n);
    return i;
}

int checkDiamonds(char c[], int len){
    int i;
    struct stack* s = NULL;
    int qtd = 0;
    int aux = 0;

    for(i = 0;i < len; i++){
        if((c[i] == '<')){
            push(&s, c[i]);
            aux = 1;
        }else if((c[i] == '>')){
            if(aux == 1){
                aux--;
                qtd++;
            }
        }
    }

    return qtd;
}