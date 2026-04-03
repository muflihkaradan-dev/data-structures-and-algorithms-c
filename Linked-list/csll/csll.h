#ifndef CSLL_H
#define CSLL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int rollno;
    char name[20];
    struct Node* next;
}Node;
void add_begin(Node**);
void add_end(Node**);
void print_node(Node*);
void add_middle(Node**);
int count_node(Node*);
void read_file(Node**);
void save_file(Node*);
void reverse_print(Node*);
void reverse_rec(Node*);
void print_rec(Node*);
void delete_all(Node**);
void delete_node(Node**);
void search_node(Node*);
void sort_data(Node*);
void reverse_links(Node**);

#endif
