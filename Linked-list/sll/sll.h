#ifndef SLL_H
#define SLL_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int rollno;
    char name[20];
    float marks;
    struct Node * next;
}Node;
void add_begin(Node**);
void print_node(Node*);
void add_mid(Node**);
void add_end(Node**);
int count_node(Node*);
void save_file(Node*);
void read_file(Node**);
void rev_print(Node*);
void print_rec(Node*);
void reverse_rec(Node*);
void delete_all(Node**);
void delete_node(Node**);
void search_node(Node*);
void sort_data(Node*);
void reverse_link(Node**);

#endif
