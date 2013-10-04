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
