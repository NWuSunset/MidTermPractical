//list.h
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node * next;
};

/* *****************YOUR TURN! ******************************** */
/* PLACE YOUR PROTOTYPE HERE */
void removeHead(node* &head);
node* copyFirstLast(node* head);
void removeTen(node* &head);

void removeDuplicates(node* curr);
void addThree(node* head);
void remove2ndNodes(node* head);

/* These functions are already written and can be called to test out your code */
void build(node * & head);      //supplied
void display_all(node * head);  //supplied
void destroy(node * &head);     //supplied


