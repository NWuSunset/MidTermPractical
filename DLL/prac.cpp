#include "dlist.h"
#include <iostream>

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

void dlist::swapAdjacent() {
  swapAdjacent(head);
}

void dlist::swapAdjacent(node* &curr) {
  //Base case (end of list) (or a list with odd number of nodes)
  if (curr == nullptr || curr->next == nullptr) {
    return;
  }

  node* first = curr;
  node* second = curr->next;

  //Swap nexts
  first->next = second->next;
  second->next = first;

  //swap previouses
  second->previous = first->previous; //second prev is now first prev
  first->previous = second; //second would be behind first now

  //Swap nodes:
  curr = second;
  
  
  swapAdjacent(curr->next->next); //move over two spaces (to get to the next adjacnet group)
}


//makes a new list of copies except three
node* dlist::copyExceptThree() {
  node* newHead = copyExceptThree(head);

  node* curr = newHead;
  //print out stuff
  while (curr) {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
  
  return newHead;
}

node* dlist::copyExceptThree(node* curr) {
  //base case (end of list)
  if (!curr) {
    return nullptr;
  }

  //skip if three
    if (curr->data == 3) {
      return copyExceptThree(curr->next);
    }
    
    /*Copy data
    node* newNode = new node();
    newNode->previous = nullptr; //for head case
    newNode->data = curr->data;
    newNode->next = copyExceptThree(curr->next);
    */ 
    node* newNode = new node { //could also do this i guess..
      curr->data,
      nullptr,
      copyExceptThree(curr->next)
    };
    
    if (newNode->next) { //if next is not null
      newNode->next->previous = newNode; //we can set a previous
    }
    return newNode;
  }


void dlist::insertXAfterNodes(int x) {
  insertXAfterNodes(head, x);
}

void dlist::insertXAfterNodes(node* pos, int x) {
  if (pos == nullptr) {
    return; //base case end of list
  }

  node* newNode = new node {
    x, //data
    pos,   //previous
    pos->next //next value
  };
  //put is as pos next
  pos->next = newNode;

  if (newNode->next != nullptr) { //if this node was the last in the list
    newNode->next->previous = newNode; //update next node's previous
  }

  
  if (newNode->next == nullptr) { //if tail
    tail = newNode;
  } 

  //move twice over
  insertXAfterNodes(newNode->next, x);
}
