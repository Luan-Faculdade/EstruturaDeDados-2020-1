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
int isPair(char c1, char c2); //Verifica se os caracteres se completam
int checkBracket(char c[], int len); //Verifica se os parenteses estao corretos

int main(){
    stack s;
    char seq[100];
    int len;
    printf("Insira a sequencia: ");
    scanf(" %[^\n]", &seq);
    len = strlen(seq);

    if(checkBracket(seq, len) == 1){
        printf("Balanceado\n");
    }else{
        printf("Desbalanceado\n");
    }

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

int isPair(char c1, char c2){
    if(c1 == '(' && c2 == ')'){
        return 1;
    }else if(c1 == '{' && c2 == '}'){
        return 1;
    }else if(c1 == '[' && c2 == ']'){
        return 1;
    }else{
        return 0;
    }
}

int checkBracket(char c[], int len){
    int i;
    struct stack* s = NULL;

    for(i = 0;i < len; i++){
        if((c[i] == '(') || (c[i] == '[') || (c[i] == '{')){
            push(&s, c[i]);
        }else if((c[i] == ')') || (c[i] == ']') || (c[i] == '}')){
            if(s == NULL){
                return 0;
            }else if(isPair(pop(&s), c[i]) == 0){
                return 0;
            }
        }
    }

    if(s == NULL){
        return 1;
    }else{
        return 0;
    }
}