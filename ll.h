#include <iostream>

/*
 * This header contains the structs and method declarations for
 * a linked list and node library implementation. Code inspired
 * by Dave Small's COP3503 class.
 */

// The Node struct. Currently it uses an int data type.
struct Node 
{
  /* Data members */
  int data;     // the data that the Node holds
  Node* next;   // pointer to the next Node in the list

  /* Methods */
  bool lastNode();
  // Precondition: Accepts a Node object 
  // Postcondition: Returns 1 if it is the last node, 0 if not the last node

  int length();
  // Precondition: Called on a Node object
  // Postcondition: Recursively computes the length of the list
  
};


// The LinkedList struct.
struct LinkedList
{
  /* Data members */
  Node* head;   // points to the first Node in the list

  /* Methods */
  bool empty();
  // Precondition: Called on a LinkedList object.
  // Postcondition: Returns 1 if the list is empty, 0 if not empty

  int length();
  // Precondition: Called on a LinkedList object.
  // Postconditin: Returns the length of the LinkedList
};
