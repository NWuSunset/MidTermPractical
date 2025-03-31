#include "dlist.h"


//Removes numbers greater than 9
void dlist::removeGreaterNine() {
  removeGreaterNine(head);
}


void dlist::removeGreaterNine(node* curr) {
  //base case (end of list)
  if (curr == nullptr) {
    return;
  }

  node* nextNode = curr->next;

  //if greater than 9
  if (curr->data > 9) {
    if (curr->previous) { //if there is a previous node
      //update the previous's next correctly
     curr->previous->next = curr->next;
    } else { //no previous (it would be the head of linked list)
      head = curr->next;
    }

    if (curr->next) { //if there is a next
      //update the next's previous correctly
      curr->next->previous = curr->previous;
    } else { // else it's the tail
      tail = curr->previous; //udpate tail
    }
    delete curr;
    curr = nullptr;
  } 
  removeGreaterNine(nextNode); // move onto next node
} 
