#include "ll.h"

/*
 * The cpp file for the 'll' LinkedList and Node library implementation.
 * Code inspired by Dave Small's COP3503 class.
 */

/* Node method implementations */

bool Node::lastNode()
{
  /* If next isn't a nullptr, its not the last Node */
  if ( next != 0 )
    return false;

  /* Otherwise, it is the last node */
  return true;
}

int Node::length()
{
  if ( lastNode() ) // BASE CASE
    return 1;
  else
    return 1 + next->length();
}

void Node::append( int data )
{
  if ( next == 0 ) // BASE CASE
  {
    /* The last Node has been reached, create the new one */
    Node* tmp = new Node;
    tmp->data = data;
    tmp->next = next; // will be the nullptr (or 0)
    next = tmp;
  }
  
  else
    next->append( data );
}

bool Node::contains( int value )
{
  if ( data == value )
    return true;
  if ( lastNode() )
    return false;
  else
    return next->contains( value );  
}

void Node::insertAt( int value, int const position )
{
  if ( position == 1 || lastNode() ) // BASE CASE
  {
    Node* tmp = new Node;
    tmp->data = value;
    tmp->next = next;
    next = tmp;
  }
  else
    next->insertAt( value, position-1 ); // recursive call
}


/* LinkedList method implementations */
bool LinkedList::empty()
{
  /* 
   * If the head data member of the LinkedList is 0 (nullptr)
   * then it is an empty LinkedList 
   */
  if ( head != 0 )
    return false;

  /* Otherwise, head is a nullptr and the LinkedList is empty */
  return true;
}

int LinkedList::length()
{
  if ( empty() ) // BASE CASE
    return 0;

  else 
    return head->length();
}

void LinkedList::prepend( int data )
{
  Node* tmp = new Node;  // create the new Node object
  tmp->data = data;      // set its data
  tmp->next = head;      // point next to the next Node
  head = tmp;            // make head point to the new Node object
}

int LinkedList::decapitate()
{
  int data = head->data;  // capture the data
  Node* toDelete = head;  // create a ptr to the Node to remove
  head = head->next;      // point head to the list's second item (or nullptr)
  delete toDelete;        // delete the Node object
  return data;            // return the data
}

void LinkedList::append( int data )
{
  if ( empty() )
    prepend( data );

  else
  {
    head->append( data );
  }
}

bool LinkedList::contains( int value )
{
  if ( empty() )
    return false;

  else
    return head->contains( value ); // call the Node method
}

void LinkedList::insertAt( int value, int const position )
{
  if ( position == 0 || empty() ) 
    prepend( value );
  else
    head->insertAt( value, position );
}
