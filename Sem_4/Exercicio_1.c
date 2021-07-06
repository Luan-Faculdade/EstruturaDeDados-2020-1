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
void invertList(list *l);
int somarValores(list *l);
int maiorValor(list *l);

int main(){
    list *l;
    node *n;
    l = newList();

    int i=0, opc, aux;

    printf("\nEscolha uma das opcoes a seguir");
    printf("\n1 - Incluir novo numero na lista"); // OK
    printf("\n2 - Inverter a lista e mostrar ela");
    printf("\n3 - Inserir valores na lista com distiscao entre par e impar (par no inicio e impar no fim)");
    printf("\n4 - Inserir valor em qualquer posicao da lista");
    printf("\n5 - Somar os valores inseridos na lista"); // OK
    printf("\n6 - Retornar o maior valor da lista"); // OK
    printf("\n7 - Mostrar a lista"); // OK

    do{
        printf("\n\nInsira a opcao: ");
        scanf("%i", &opc);

        switch(opc){
            case 1:
                printf("Insira um valor a lista: ");
                scanf("%i", &aux);
                addNode(l, aux);
                break;
            case 2:
                showList(l);
                invertList(l);
                showList(l);
                i++;
                break;
            case 3:
                break;
            case 4:
                printf("\nO valor total dos valores inseridos na lista e de: %i", somarValores(l));
                i++;    
                break;
            case 5:                
                break;
            case 6:
                printf("\nO maior valor na lista e: %i", maiorValor(l));
                i++;
                break;
            case 7:
                showList(l);
                i++;
                break;
            default:
                printf("\nOpcao incorreta!");
                break;
        }
    }while(i == 0);
    
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

void invertList(list *l){
    node *prev, *cur, *next;
    prev = NULL;
    cur = l;
    while(cur){
        next = cur ->prox;
        cur->prox = prev;
        prev = cur;
        cur = next;
    }
    l = prev;
}

void insertAnyPos(list *l, int pos, int value){
    if(pos < 1 || pos > length(l) + 1){
        printf("\nPosicao invalida!");
    }else{
        while(pos--){
            if(pos == 0){
                node *temp;
                temp -> prox = l;

                l = temp;
            }
        }
    }
}

int somarValores(list *l){
    node *n;
    int valorTotal=0;
    if(isEmpty(l)){
        printf("\nA lista está vazia");
    }else{
        n = l -> first;
        while (n != NULL){
            valorTotal += n->info;
            n = n -> prox;
        }        
    }
    return valorTotal;
}

int maiorValor(list *l){
    node *n;
    int maiorValor=0;
    if(isEmpty(l)){
        printf("\nA lista está vazia");
    }else{
        n = l -> first;
        while (n != NULL){
            if(maiorValor < n -> info){
                maiorValor = n->info;
            }
            n = n -> prox;
        }        
    }
    return maiorValor;
}