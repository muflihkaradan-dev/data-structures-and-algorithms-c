#ifndef DLL_H
#define DLL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}Node;
void add_begin();
void add_end();
void print();
void reverse_print();
void search_node();
void read_file();
void add_middle();
void save_file();
int count_node();
void delete_node();
void delete_all();
void delete_duplicate();
void sort_node();
void reverse_rec(Node*);
void reverse_link();

#endif
