//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;		//some questions use a char * data;
    node * previous;
    node * next;
};

class dlist
{
public:
  //These functions are already written
  dlist();         //supplied
  ~dlist();        //supplied
  void build();   //supplied
  void display(); //supplied
  
  
  /* *****************YOUR TURN! ******************************** */
     /* place your prototype here */
  void removeGreaterNine();
  void removeGreaterNine(node* curr);

  void swapAdjacent();
  void swapAdjacent(node* &curr);

  node* copyExceptThree();
  node* copyExceptThree(node* curr);

  void insertXAfterNodes(int x);
  void insertXAfterNodes(node* pos, int x);
private:
         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL
};

//adding at specific positions
//remove at specific postions
//copying the list
