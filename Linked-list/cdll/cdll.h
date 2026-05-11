#ifndef CDLL_H
#define CDLL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct CDLL{
    struct CDLL * prev;
    int data;
    struct CDLL * next;
}Node;
//fuctions prototypes
void add_begin();
void add_end();
void add_middle();
void print();
void search_node();
void read_file();
void save_file();
void reverse_print();
int count_node();
void delete_node();
void delete_duplicate();
void delete_all();
void sort_node();
void reverse_rec(Node*);
void reverse_link();

#endif

