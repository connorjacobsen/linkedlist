#include <iostream>

/*
 * This header contains the structs and method declarations for
 * a linked list and node library implementation. Code inspired
 * by Dave Small's COP3503 class.
 */

// The Node struct. Currently it uses an int data type.
struct Node 
{
  int data;     // the data that the Node holds
  Node* next;   // pointer to the next Node in the list
}

// The LinkedList struct.
struct LinkedList
{
  Node* head;   // points to the first Node in the list
}
