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

  unsigned int length();
  // Precondition: Called on a Node object
  // Postcondition: Recursively computes the length of the list

  void append( int data );
  // Precondition: Triggered by the LinkedList append method
  // Postcondition: Adds a Node with data 'data' to the end of the list

  bool contains( int value );
  // Precondition: Called on a Node object
  // Postcondition: Returns 1 if the Node contains the value, 0 otherwise

  void insertAt( int value, unsigned int const position );
  // Precondition: Called on a Node object
  // Postcondition: Recursively inserts a Node with the data 'value' and the given position

  int removeAt( unsigned int const position );
  // Precondition: Called on a Node object.
  // Postcondition: If it is the Node at 'position' it is removed and its data is returned,
  //   else it moves on to the next Node recursively.

  void printList( unsigned int const position );
  // Precondition: Called on a Node object, accepts the current position.
  // Postcondition: Prints the Node's data, and if not last node, calls itself on the next Node
  //
  // Useful for visualization and / or debugging.

  int decaudate();
  // Precondition: Called on a Node object by its LinkedList.
  // Postcondition: Recursively finds the last Node and deletes its data.
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

  unsigned int length();
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

  void insertAt( int value, unsigned int const position );
  // Precondition: Called on a LinkedList object
  // Postcondition: Inserts a Node at the given position with 'value' as its data,
  //   or inserts the Node at the end of the list if the position is out of index.

  int removeAt( unsigned int const position );
  // Precondition: Called on a LinkedList object.
  // Postcondition: Deletes the Node at 'position' and returns its data. If the
  //   position does not exist, it will remove the last Node in the list.

  void printList();
  // Precondition: Called on a LinkedList object.
  // Postcondition: Prints out the data for each Node in the list and its position.

  int decaudate();
  // Precondition: Called on a LinkedList object.
  // Postcondition: Removes the tail of the LinkedList and returns its data.
};
