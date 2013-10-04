#include "ll.h"

/*
 * The cpp file for the 'll' LinkedList and Node library implementation.
 * Code inspired by Dave Small's COP3503 class.
 */

bool Node::lastNode()
{
  /* If next isn't a nullptr, its not the last Node */
  if ( next != 0 )
    return false;

  /* Otherwise, it is the last node */
  return true;
}
