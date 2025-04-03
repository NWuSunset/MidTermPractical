#include "clist.h"
#include <iostream>


int main()
{
    clist object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    //node* newHead = object.copyExceptTwo(); 
    //object.sumAllData();
    //object.add12After3();

    object.removeAllOdd();
    object.display(); //resulting list after your function call!
    
    return 0;
}
