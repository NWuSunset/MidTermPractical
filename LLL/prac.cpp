#include "list.h"


void removeHead(node* & head) {
  //Head should never be null so we don't need a check (always has 10-15 random values in the list)

  //but just to be safe :)
  if (head == nullptr) return;
  
  node* temp = head;
  head= head->next;
  delete temp;
}

//copies list, only first and last vlaues though. returns head of new list
node* copyFirstLast(node* head) {
  node* newHead = new node();
  newHead->data = head->data;


  node* curr = head;
  while (curr->next != nullptr) {
    curr = curr->next;
  }

  //end of list
  newHead->next = curr;
  return newHead;
}

//removes all values of 10
void removeTen(node* &head) {
  
  if (head == nullptr) {
    return;
  }
  
  if (head->data == 10) {
    node* temp = head;
    head = head->next;
    delete temp;
    removeTen(head);
    //delete temp;
  } else {
    removeTen(head->next);
  }
}

//adding a while loop would be better but...
void removeDuplicates(node* curr) {
  //base case (list end)
  if (curr == nullptr) { //head null
    return;
  }

  node* pos = curr->next;
  node* prev = curr;

  while (pos != nullptr) {
    if (pos->data == curr->data) { //delete data if duplicate
      prev->next = pos->next; //update previous pointer
      node* temp = pos;
      pos = pos->next; //update pos (now prev and pos are properly updated)
      delete temp;
    } else {
    prev = pos;
    pos = pos->next;
    }
  }

  //Then move onto the next curr in list 
  removeDuplicates(curr->next);
}

//add three after each instance of 3 in linked list
void addThree(node* head) {
  node* curr = head;
  while (curr != nullptr) {
    if (curr->data == 3) { //add a duplicate node after
      node* newNode = new node {
        3,
        curr->next
      };
      curr->next = newNode; //set curr next to this new node.
      curr = newNode->next; //move up list
    } else {
      curr = curr->next;
    }
  }
}

//removes every second node
void remove2ndNodes(node* head) {
  node* curr = head; //start at the second one

  while (curr != nullptr && curr->next != nullptr ) {
    node* temp = curr->next; //2nd node
    curr->next = curr->next->next;
    delete temp;
    curr = curr->next;
  }
}

