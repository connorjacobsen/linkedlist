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

unsigned int Node::length()
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

void Node::insertAt( int value, unsigned int const position )
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

int Node::removeAt( unsigned int const position )
{
  if ( position == 1 || lastNode() ) // BASE CASE
  {
    int value = next->data; // get the data to return (from next Node)
    Node* toDelete = next; // create ptr to Node to delete
    next = next->next;     // make sure list not broken
    delete toDelete;       // delete the desired Node
    return value;
  }
  else
    return next->removeAt( position-1 );
}

void Node::printList( unsigned int const position )
{
  if ( lastNode() ) // BASE CASE
    std::cout << "Position: " << position << ", Data: " << data << std::endl;
  else
  {
    std::cout << "Position: " << position << ", Data: " << data << std::endl;
    next->printList( position+1 ); // recursive step
  }
}

int Node::decaudate()
{
  if ( next->lastNode() ) // BASE CASE
  {
    int value = next->data; // named value to not conflict with data member name
    Node* toDelete = next;
    next = 0; // set next to be the nullptr
    delete toDelete;
    return value;
  }
  else              // recursive step
    return next->decaudate();
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

unsigned int LinkedList::length()
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

void LinkedList::insertAt( int value, unsigned int const position )
{
  if ( position == 0 || empty() ) 
    prepend( value );
  else
    head->insertAt( value, position );
}

int LinkedList::removeAt( unsigned int const position )
{
  if ( position == 0 ) // If we just want to remove the first element
    decapitate();      // we can use the decapitate function.
  else                 // Else we need remove at.
    return head->removeAt( position );
}

void LinkedList::printList()
{
  if ( empty() ) // If empty, print to screen
    std::cout << "This LinkedList is empty!" << std::endl;
  else           // Else call printList on the Nodes
    head->printList( 0 );
}

int LinkedList::decaudate()
{
  return head->decaudate();
}
