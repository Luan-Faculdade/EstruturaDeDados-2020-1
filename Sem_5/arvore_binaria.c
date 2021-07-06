#include <stdio.h>
#include <stdlib.h>

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
int height(node *n);
int isLeaf(node *n);
int getLevel(node *n);
int height(node *n);
int complete(node *n);

int main(){
    node *n;

    n = makeTree(14);
    setLeft(setLeft(n, 4), 3);
    setRight(left(n), 10);
    setLeft(setRight(n, 22), 18);
    setLeft(setRight(right(n), 25), 22);

    printf("Pre-ordem: ");
    preOrder(n);
    printf("\nEm ordem: ");
    inOrder(n);
    printf("\nPos-ordem: ");
    postOrder(n);

    printf("\nTamanho: %i", height(n));

    if(complete(n) == 0){
        printf("\nNao completa\n");
    }else{
        printf("\nCompleta\n");
    }

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
            return complete(right(n)) && complete(left(n));
        }
    }else{
        return 0;
    }
}