#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    //removeHead(head);
    //node* newHead = copyFirstLast(head);
    //    removeTen(head);
    //removeDuplicates(head);
    //addThree(head);
    remove2ndNodes(head);
    display_all(head);
    
    return 0;
}
