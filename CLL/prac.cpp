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

  //print out result
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

//copy data
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

void clist::add12After3() {
  add12After3(rear->next, rear);
}

void clist::add12After3(node* pos, node* end) {
  //base case: Hit end
  if (pos == end) {
    node* newNode = new node {
      12,
      pos->next
    };
    pos->next = newNode;
    return; 
  }

  if (pos->data == 3) {
    node* newNode = new node {
      12, //data of 12
      pos->next //add next (going between pos and pos->next
    };
    pos->next = newNode;
  }

  add12After3(pos->next, end);
}


void clist::removeAllOdd() {
  removeAllOdd(rear->next, rear);

  //edge case (if all nodes were odd) (if circles backon itself)
  if (rear && rear->next == rear && rear->data % 2 != 0) {
    delete rear;
    rear = nullptr;
  }
    
}

void clist::removeAllOdd(node* &pos, node* end) {
  if (pos == end) {
    if (pos->data % 2 != 0) { //if odd
      //remove
      node* temp = pos;
      pos = pos->next; //update the position pointer
      rear = pos;
      delete temp; //delete the old value
    }
    return;
  }

  if (pos->data % 2 != 0) {
    node* temp = pos;
    pos = pos->next;
    delete temp;
    removeAllOdd(pos, end); //incase consecutive odds 
  } else {
    removeAllOdd(pos->next, end);
  }
}
