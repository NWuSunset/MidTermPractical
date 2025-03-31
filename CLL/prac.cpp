#include "clist.h"
#include <iostream>
node* clist::copyExceptTwo() {

  //start at the head of the list
  node* result = copyExceptTwo(rear->next, rear); 

  //make the list circular
  if (result != nullptr) {
    node* temp = result;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = result; //loop back to beggining
  }

  if (result != nullptr) {
    //Print out result
    node* n = result->next;
    std::cout << result->data << " ";
    while (n != result) {
      std::cout << n->next->data << " ";
      n = n->next;
    }
    std::cout << std::endl;
  }
  return result;
}

node* clist::copyExceptTwo(node* curr, node* stop) {
  if (curr == stop) { //base case (hit end of list)
    
    if (curr->data != 2) { //if isn't two
      node* newNode = new node();
      newNode->data = curr->data;
      newNode->next = nullptr;
      return newNode;
    }
    return nullptr; //return null if two
  }

  if (curr->data == 2) { //skip if node value == 2
    return copyExceptTwo(curr->next, stop);
  }


  //create a new node to be added to the new list
  node* newNode = new node();
  newNode->data = curr->data;
  newNode->next = nullptr;
   
  newNode->next = copyExceptTwo(curr->next, stop);
  return newNode;
}

void clist::sumAllData() {
  //start at head
  int sum = 0;
  sumAllData(rear->next, rear, sum);

  std::cout << sum << std::endl;
}

void clist::sumAllData(node* curr, node* end, int &sum) {
  //Base case (end of list)
  if (curr == end) {
    //if even
    if (curr->data % 2 == 0) {
      sum += curr->data;
    }
    return;
  }

  //if even, add to sum
  if (curr->data % 2 == 0) {
    sum += curr->data;
  }

  sumAllData(curr->next, end, sum); //recursions
}
