#include<stdio.h>
#include<stdlib.h>

typedef struct NodeItem {
  int info;
  struct NodeItem *prox;
  struct NodeItem *prev;  
} node;

typedef struct {
  node *first;
  node *last;
} list;

list *newList();
node *newNode(int value);
node *addNodeInit(list *l, int value);
node *addNodeMid(list *l, node *ant, int value);
node *addNodeEnd(list *l, int value);
node *findNode(list *l, int value);
void delNode(list *l, int value);
int isEmpty(list *l);
int length(list *l);
void showList(list *l);
void showListReverse(list *l);
int maiorValor(list *l);

int main(){
    list *l;
    l = newList();

    int i=0, opc, aux, opc2, ant;

    printf("\nEscolha uma das opcoes a seguir");
    printf("\n1 - Incluir novo numero na lista"); // OK
    printf("\n2 - Mostrar lista inversa");//OK
    printf("\n3 - Incluir novos numeros na lista com diferenca de par e impar (par no inicio e impar no fim)");//OK
    printf("\n4 - Inserir valores de forma ordenada");//Ok
    printf("\n5 - Ordernar lista na forma descrecente");
    printf("\n6 - Remover maior elemento da lista");//OK
    printf("\n7 - Mostrar a lista");//OK

    do{
        printf("\n\nInsira a opcao: ");
        scanf("%i", &opc);

        switch(opc){
            case 1:
                printf("\nEscolha uma das opcoes a seguir");
                printf("\n1 - Inserir no inicio");
                printf("\n2 - Inserir no meio");
                printf("\n3 - Inserir no fim");
                printf("\n\nInsira a opcao: ");
                scanf("%i", &opc2);

                switch(opc2){
                  case 1:
                    printf("\nInsira um valor a lista: ");
                    scanf("%i", &aux);
                    addNodeInit(l, aux);
                    break;
                  case 2:
                    printf("\nInsira um valor a lista: ");
                    scanf("%i", &aux);
                    printf("\nInsira o valor anterior: ");
                    scanf("%i", &ant);
                    addNodeMid(l, findNode(l, ant), aux);
                    break;
                  case 3:
                    printf("Insira um valor a lista: ");
                    scanf("%i", &aux);
                    addNodeEnd(l, aux);
                    break;
                  default:
                    printf("\nOpcao invalida");
                    break;
                }
    
                break;
            case 2:
                showListReverse(l);
                i++;
                break;
            case 3:
                printf("\nInsira um valor a lista: ");
                scanf("%i", &aux);
                if(aux % 2){
                  addNodeInit(l, aux);
                }else{
                  addNodeEnd(l, aux);
                }
                break;
            case 4: 
                printf("\nInsira um valor a lista: ");
                scanf("%i", &aux);
                if(l -> first >= aux){
                  addNodeEnd(l, aux);
                }else{
                  addNodeInit(l, aux);
                }
                break;
            case 5:

                break;
            case 6:
              delNode(l, maiorValor(l));
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
    l -> last = NULL;
    return l;
}

node *newNode(int value){
    node *n = (node *)malloc(sizeof(node));
    n -> info = value;
    n -> prev = NULL;
    n -> prox = NULL;
    return n;
}

node *addNodeInit(list *l, int value) {
  node *n = newNode(value);
  if (isEmpty(l)) {
    l->first = n;
    l->last = n;
  } else {
    n->prox = l->first;
    l->first->prev = n;
    l->first = n;
  }

  return n;
}

node *addNodeMid(list *l, node *ant, int value) {
  node *n, *prox;

  if (ant == NULL) {
    n = addNodeInit(l, value);
  } else if(ant == l->last) {
    n = addNodeEnd(l, value);
  } else {
    n = newNode(value);
    prox = ant->prox;
    n->prev = ant;
    n->prox = prox;
    ant->prox = n;
    prox->prev = n;
  }

  return n;
}

node *addNodeEnd(list *l, int value) {
  node *n = newNode(value);
  if (isEmpty(l)) {
    l->first = n;
    l->last = n;
  } else {
    n->prev = l->last;
    l->last->prox = n;
    l->last = n;
  }

  return n;
}

node *findNode(list *l, int value){
    node *n = l -> first;
    while(n != NULL && n -> info != value){
        n = n -> prox;
    }
    return n;
}

void delNode(list *l, int value) {
  node *n, *prev, *next;
  n = findNode(l, value);
  if (n != NULL) {
    prev = n->prev;
    next = n->prox;

    if (n == l->first) {
      l->first = next;
    }
    if (n == l->last) {
      l->last = prev;
    }

    if (prev != NULL){
      prev->prox = next;
    }
    if (next != NULL) {
      next->prev = prev;
    }

    free(n);
  }
}

void showList(list *l) {
  node *n;
  if (isEmpty(l)) {
    printf("\nA lista esta vazia");
  } else {
    printf("\nA lista possui %i elemento(s), sendo: ", length(l));
    n = l->first;
    while(n != NULL) {
      if (n->prev != NULL && n->prox != NULL)
        printf("\n=> %i [Ant: %i, Prox: %i]", n->info, n->prev->info, n->prox->info);
      else if (n->prev != NULL)
        printf("\n=> %d [Ant: %d, Prox: NULL]", n->info, n->prev->info);
      else if (n->prox != NULL)
        printf("\n=> %d [Ant: NULL, Prox: %d]", n->info, n->prox->info);
      else
        printf("\n=> %d [Ant: NULL, Prox: NULL]", n->info);
      n = n->prox;
    }
    printf("\n");
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

void showListReverse(list *l) {
  node *n;
  if (isEmpty(l)) {
    printf("\nA lista esta vazia");
  } else {
    printf("\nA lista possui %i elemento(s), sendo: ", length(l));
    n = l->last;
    while(n != NULL) {
      if (n->prev != NULL && n->prox != NULL)
        printf("\n=> %i [Ant: %i, Prox: %i]", n->info, n->prev->info, n->prox->info);
      else if (n->prev != NULL)
        printf("\n=> %d [Ant: %d, Prox: NULL]", n->info, n->prev->info);
      else if (n->prox != NULL)
        printf("\n=> %d [Ant: NULL, Prox: %d]", n->info, n->prox->info);
      else
        printf("\n=> %d [Ant: NULL, Prox: NULL]", n->info);
      n = n->prev;
    }
    printf("\n");
  }
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