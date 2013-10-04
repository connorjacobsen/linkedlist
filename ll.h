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
  
};

// The LinkedList struct.
struct LinkedList
{
  /* Data members */
  Node* head;   // points to the first Node in the list

  /* Methods */
  Node* getHead() { return head; }
  // Precondition: The LinkedList must be non-empty
  // Postconditon: Returns the first item of the LinkedList
};
