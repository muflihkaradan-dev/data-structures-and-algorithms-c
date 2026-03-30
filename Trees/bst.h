#ifndef BST_H
#define BST_H

#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    struct tree *left;
    int num;
    struct tree *right;
}BST;
void insertNode(BST**,int);
void preorder(BST*);
void inorder(BST*);
void postorder(BST*);
BST* searchNode(BST*,int n);
void deleteNode(BST**,int n);

#endif
