#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tree{
    int info;
    struct tree *father;
    struct tree *left;
    struct tree *right;
}node;

int info(node *n);
node *father(node *n);
node *brother(node *n);
node *left(node *n);
node *right(node *n);
int isLeft(node *n);
int isRight(node *n);
node *makeTree(int value);
node *setLeft(node *n, int value);
node *setRight(node *n, int value);
void freeTree(node *n);
void preOrder(node *n);
void inOrder(node *n);
void postOrder(node *n);
node *search(node *n, int value);
node *setNodeLeft(node *tree, node *n);
node *setNodeRight(node *tree, node *n);
node *insert(node *n, int value);
node *deleteRoot(node *tree);
node *delete(node *tree, int value);
int height(node *n);
int isLeaf(node *n);
int getLevel(node *n);
int height(node *n);
node *root(node *n);
int complete(node *n);
void getHLValues(node *n);
int isSearchTree(node *n);

int menorV = INFINITY, maiorV = -INFINITY;

int main(){
    node *n;

    int i=0, opc, aux;

    /*n = makeTree(14);
    setLeft(setLeft(n, 4), 3);
    setRight(left(n), 10);
    setLeft(setRight(n, 22), 18);
    setLeft(setRight(right(n), 25), 22); */ //Nao ajusta automaticamente
    
    /*n = makeTree(0);
    insert(n, 1);
    insert(n, 2);
    insert(n, 3);
    insert(n, 4);
    insert(n, 5);*/ //Nao funciona na hora de obter tamanho

    printf("\nEscolha uma das opcoes a seguir");
    printf("\n1 - Incluir novo numero na arvore"); // OK
    printf("\n2 - Mostrar arvore em ordem, pos ordem e pre ordem, verificar se e completa, se e de busca e apresentar o tamanho");

    n = NULL;

    do{
        printf("\n\nInsira a opcao: ");
        scanf("%i", &opc);

        switch(opc){
            case 1:
                printf("Insira um valor a arvore: ");
                scanf("%i", &aux);
                n = insert(n, aux);
                break;
            case 2:
                printf("Pre-ordem: ");
                preOrder(n);
                printf("\nEm ordem: ");
                inOrder(n);
                printf("\nPos-ordem: ");
                postOrder(n);

                printf("\nTamanho: %i", height(n));

                if(complete(n) == 0){
                    printf("\nNao completa");
                }else{
                    printf("\nCompleta");
                }

                getHLValues(n);
                printf("\nO maior valor da arvore e %i e o menor e %i", maiorV, menorV);

                if(isSearchTree(n) == 1){
                    printf("\nNao e uma arvore de busca\n");
                }else{
                    printf("\nE uma arvore de busca\n");
                }
                i++;
                break;
            default:
                printf("\nOpcao incorreta!");
                break;
        }
    }while(i == 0);

    return 0;
}

int info(node *n){
    return n->info;
}

node *left(node *n){
    return n->left;
}

node *right(node *n){
    return n->right;
}

node *father(node *n){
    return n->father;
}

node *brother(node *n){
    if(father(n) == NULL){
        return NULL;
    }else if(isLeft(n)){
        return right(father(n));
    }else{
        return left(father(n));
    }
}

int isLeft(node *n){
    if(father(n) == NULL){
        return 0;
    }else{
        return left(father(n)) == n;
    }
}

int isRight(node *n){
    if(father(n) == NULL){
        return 0;
    }else{
        return right(father(n)) == n;
    }
}

node *makeTree(int value){
    node *n = malloc(sizeof(node));
    n->info = value;
    n->father = n->left = n->right = NULL;
    return n;
}

node *setLeft(node *n, int value){
    n->left = makeTree(value);
    n->left->father = n;
    return n->left;
}

node *setRight(node *n, int value){
    n->right = makeTree(value);
    n->right->father = n;
    return n->right;
}

void freeTree(node *n){
    if(n != NULL){
        node *nd = father(n);
        freeTree(left(n));
        freeTree(right(n));

        if(isLeft(n)){
            nd->left = NULL;
        }else if(isRight(n)){
            nd->right = NULL;
        }
        free(n);
    }
}

void preOrder(node *n){
    if(n != NULL){
        printf("%i ", info(n));
        preOrder(left(n));
        preOrder(right(n));
    }
}

void inOrder(node *n){
    if(n != NULL){
        preOrder(left(n));
        printf("%i ", info(n));
        preOrder(right(n));
    }
}

void postOrder(node *n){
    if(n != NULL){
        preOrder(left(n));
        preOrder(right(n));
        printf("%i ", info(n));
    }
}

node *search(node *n, int value){
    if(n == NULL || info(n) == value){
        return n;
    }else if(value < info(n)){
        return search(left(n), value);
    }else{
        return search(right(n), value);
    }
}

node *setNodeLeft(node *tree, node *n){
    tree->left = n;
    if(n != NULL){
        n->father = tree;
    }
    return n;
}

node *setNodeRight(node *tree, node *n){
    tree->right = n;
    if(n != NULL){
        n->father = tree;
    }
    return n;
}

node *insert(node *n, int value){
    if(n == NULL){
        return makeTree(value);
    }else if(value < info(n)){
        setNodeLeft(n, insert(left(n), value));
    }else{
        setNodeRight(n, insert(right(n), value));
    }
    return n;
}

node *deleteRoot(node *tree){
  node *n, *nd;

  if(left(tree) == NULL){
    n = right(tree);
  }else{
    n = left(tree);
    
    while(right(n) != NULL){
      n = right(n);
    }

    if(father(n) != tree){
      nd = father(n);
      setNodeRight(nd, left(n));
      setNodeLeft(n, left(tree));
    }

    setNodeRight(n, right(tree));
  }

  if(n != NULL){
    n->father = NULL;
  }

  free(tree);

  return n;
}

node *delete(node *tree, int value){
  node *n = search(tree, value);
  node *nd = father(n);

  if(nd == NULL){
    return deleteRoot(n);
  }

  if(isLeft(n)){
    setNodeLeft(nd, deleteRoot(n));
  }else{
    setNodeRight(nd, deleteRoot(n));
  }

  return tree;
}


int isLeaf(node *n){
    return right(n) == NULL && left(n) == NULL;
}

int getLevel(node *n){
    if(father(n) == NULL){
        return 0;
    }else{
        return getLevel(father(n)) + 1;
    }
}

int height(node *n){
    int heightL, heightR;

    if(n != NULL){
        if(isLeaf(n)){
            return getLevel(n);
        }else{
            heightL = height(left(n));
            heightR = height(right(n));

            if(heightR < heightL){
                return heightL;
            }else{
                return heightR;
            }
        }
    }else{
        return 0;
    }
}

node *root(node *n){
    while(father != NULL){
        n = father(n);
    }

    return n;
}

int complete(node *n){
    if(n != NULL){
        if(isLeaf(n)){
            return getLevel(n) == height(root(n));
        }else{
            return complete(left(n)) && complete(right(n));
        }
    }else{
        return 0;
    }
}

void getHLValues(node *n){

    if(n != NULL){
        if(menorV > info(n)){
            menorV = info(n);
        }

        if(maiorV < info(n)){
            maiorV = info(n);
        }
        getHLValues(left(n));
        getHLValues(right(n));
    }
}

int isSearchTree(node *n){
    int check;

    check = 1;

    if(n != NULL){
        if(left(n) != NULL){
            check = info(left(n)) < info(n);
        }

        if(right(n) != NULL){
            check = info(n) <= info(right(n)) && check;
        }

        return isSearchTree(left(n)) && isSearchTree(right(n)) && check;
    }else{
        return 1;
    }
}