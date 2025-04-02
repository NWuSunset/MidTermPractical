#include "dlist.h"


int main()
{
    dlist object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    //    object.removeGreaterNine();
    //object.swapAdjacent();
    node* newHead = object.copyExceptThree();
    //object.display();
    
    return 0;
}
