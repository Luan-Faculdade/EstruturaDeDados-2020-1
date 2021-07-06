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
node *search(node *n, int value);
node *setNodeLeft(node *tree, node *n);
node *setNodeRight(node *tree, node *n);
node *insert(node *n, int value);
node *deleteRoot(node *tree);
node *delete(node *tree, int value);


int main(){
    node *n;
    
    n = makeTree(2);
    int j;

    for(j=3; j < 100; j++){
        insert(n, j);
    }

    /*insert(n, 1);
    insert(n, 2);
    insert(n, 3);
    insert(n, 4);
    insert(n, 5);*/


    printf("Pre-ordem: ");
    preOrder(n);
    printf("\nEm ordem: ");
    inOrder(n);
    printf("\nPos-ordem: ");
    postOrder(n);

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
        inOrder(left(n));
        printf("%i ", info(n));
        inOrder(right(n));
    }
}

void postOrder(node *n){
    if(n != NULL){
        postOrder(left(n));
        postOrder(right(n));
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