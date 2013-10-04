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

  void append( int data );
  // Precondition: Triggered by the LinkedList append method
  // Postcondition: Adds a Node with data 'data' to the end of the list

  bool contains( int value );
  // Precondition: Called on a Node object
  // Postcondition: Returns 1 if the Node contains the value, 0 otherwise

  void insertAt( int value, int const position );
  // Precondition: Called on a Node object
  // Postcondition: Recursively inserts a Node with the data 'value' and the given position
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

  void prepend( int data );
  // Precondition: Accepts an int
  // Postcondition: Adds a Node to the beginning of the LinkedList with the desired data

  int decapitate();
  // Precondition: Called on a non-empty LinkedList
  // Postcondition: Returns the data of the removed Node object.

  void append( int data );
  // Precondition: Must be called on a LinkedList object
  // Postcondition: Appends a new Node object to the end of the LinkedList

  bool contains( int value );
  // Precondition: Called on a LinkedList object
  // Postcondition: Returns 1 if the LinkedList contains the value, 0 otherwise

  void insertAt( int value, int const position );
  // Precondition: Called on a LinkedList object
  // Postcondition: Inserts a Node at the given position with 'value' as its data,
  //   or inserts the Node at the end of the list if the position is out of index.
};
