//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class clist
{
   public:
   		//These functions are already written
   		clist();			//supplied
   		~clist();		//supplied
   		void build();	//supplied
   		void display();	//supplied

	/* *****************YOUR TURN! ********************* */
	//Write your function prototype here:
  node* copyExceptTwo(); //returns rear of new list?
  node* copyExceptTwo(node* curr, node* stop);

  void sumAllData();
  void sumAllData(node* curr, node* end, int &sum);

  void add12After3(); //adds node with value 12 after a node with value 3
  void add12After3(node *pos, node* end);

  void removeAllOdd();
  void removeAllOdd(node* &pos, node* end);
	private:
		node * rear;
};
