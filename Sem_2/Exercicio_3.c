#include<stdio.h>
#include<stdlib.h>

#define NUM 50

//Codigo por Luan Emanuel, RA 2143860.

typedef struct {
    int top;
    int vet[NUM];
}stack;

void newStack(stack *s); //Gera uma nova pilha
int isEmpty(stack *s); //Indica se a pilha esta vazia
int isFull(stack *s); //Indica se a pilha esta cheia
void push(stack *s, int valor); //Adiciona um valor a pilha
int pop(stack *s); // Remove um valor da pilha
int top(stack *s); // Aponta o valor do topo da pilha

int main(){
    stack s;
    int i=0, opc, car, manobras=0;

    printf("\n==== Estacionamento ====");
    printf("\n\nOpcoes:");
    printf("\n1-Entrar um carro");
    printf("\n2-Sair um carro");
    printf("\n3-Fechar estacionamento\n\n"); //Menu de selecao das opcoes

    newStack(&s);
    do{
        printf("Selecione uma opcao: ");
        scanf("%i", &opc);

        switch(opc){
            case 1: //Inseri o carro no estacionamento (pilha)
                printf("\nInsira o carro: ");
                scanf("%i", &car);
                push(&s, car);
                break;
            case 2: // Remove o carro do estacionamento
                printf("\nInsira o carro: ");
                scanf("%i", &car);
                int k, aux, j;
                aux = 0;
                k = 0;
                do{
                    int carAux = top(&s);
                    int rua[NUM];
                    if(carAux != car){ //Se o carro nao for o escolhido soma uma manobra
                        manobras++;
                        rua[aux] = pop(&s);
                        aux++;
                    }else{ //Caso o carro seja o escolhido, remove ele do estacionamento, devolve em ordem os outros carros e finaliza o laco
                        pop(&s);
                        for(j = aux; j > 0; j--){
                            push(&s, rua[aux-1]);
                        }
                        k=1;
                    }
                }while(k==0);
                break;
            case 3: // Apresenta numero de manobras no dia
                printf("\nO estacionamento realizou %i manobras neste dia", manobras);
                i++;
                break;
            default: //Loop de resposta incorreta
                printf("Opcao incorreta\n");
                break;
        }
    }while(i==0);

    return 0;
}

void newStack(stack *s){
    s -> top = -1;
}

int isEmpty(stack *s){
    return s -> top == -1;
}

int isFull(stack *s){
    return s -> top == NUM;
}

void push(stack *s, int valor){
    if (isFull(s)){
        printf("\nStack Overflow!");\
        exit(1);
    }

    s->vet[++s->top] = valor;
}

int pop(stack *s){
    if (isEmpty(s)){
        printf("\nStack Underflow!");
        exit(1);
    }
    return s->vet[s->top--];
}

int top(stack *s){
    if (isEmpty(s)){
        printf("\nStack Underflow!");
        exit(1);
    }

    return s->vet[s->top];
}