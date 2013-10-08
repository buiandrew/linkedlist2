/* This is the implementation file for the ll2.h header. */
#include "ll2.h"

bool LinkedList::empty()
{
  if ( head == 0 && tail == 0 )
    return true;
  return false;
}

void LinkedList::prepend( int data )
{
  Node* tmp = new Node();
  tmp->next = head;
  tmp->data = data;
  head = tmp;
}

void LinkedList::append( int data )
{
  Node* tmp = new Node();
  tail->next = tmp;
  tmp->next = 0;
  tmp->data = data;
  tail = tmp;
}

void LinkedList::insertAt( int data, unsigned int const position )
{
  Node* node = head;
  for ( int i = 1; i < position; i++ ) {
    node = node->next;
  }
  Node* tmp = new Node();
  tmp->next = node->next;
  tmp->data = data;
  node->next = tmp;
}

int LinkedList::decapitate()
{
  Node* tmp = head;
  head = head->next;
  int value = tmp->data;
  delete tmp;
  return value;
}

int LinkedList::decaudate()
{
  Node* node = head;
  while ( node->next != tail )
  {
    node = node->next;
  }
  Node* tmp = node->next;
  int value = tmp->data;
  node->next = 0;
  tail = node;
  delete tmp;
  return value;
}

int LinkedList::removeAt( unsigned int const position )
{
  Node* node = head;
  for ( int i = 1; i < position; i++ ) {
    node = node->next;
  }
  Node* tmp = node->next;
  node->next = tmp->next;
  int value = tmp->data;
  delete tmp;
  return value;
}

void LinkedList::clear()
{
  Node* node = head;
  head = 0; // nullptr
  while ( node != tail )
  {
    Node* tmp = node;
    node = node->next;
    delete tmp;
  }
  // now node == tail
  tail = 0; // nullptr
  delete node;
}

int LinkedList::itemAtHead()
{
  return head->data;
}

int LinkedList::itemAtTail()
{
  return tail->data;
}

int LinkedList::itemAt( unsigned int const position )
{
  Node* node = head;
  for ( int i = 1; i < position; i++ ) {
    node = node->next;
  }
  return node->next->data;
}

unsigned int LinkedList::length()
{
  Node* node = head;
  unsigned int length = 0;
  while ( node != tail )
  {
    length++;
    node = node->next;
  }
  return ++length;
}

bool LinkedList::contains( int value )
{
  Node* node = head;
  while ( node != tail )
  {
    if ( value == node->data )
      return true;
    node = node->next;
  }
  if ( value == node->data )
    return true;
  return false;
}

void LinkedList::removeDuplicates()
{
  if ( head->data == head->next->data ) {
    decapitate();
  }
  Node* node = head; // get first node
  unsigned int len = length();
  while ( node->next != tail )
  {
    while ( node->data == node->next->data ) {
      Node* tmp = node->next;
      node->next = tmp->next;
      delete tmp;
    }
    int value = node->data;
    Node* n = head;
    while ( n->next != tail) {
      if ( value == n->next->data ) {
	if ( n != tail ) {
	  Node* tmp = n->next;
	  n->next = tmp->next;
	  delete tmp;
	}
      }
      if ( n != tail )
	n = n->next;
    }
    node = node->next;
  }
}

void LinkedList::printList()
{
  if ( empty() )
    std::cout << "LinkedList is empty!" << std::endl;
  else 
  {
    Node* tmp = head;
    unsigned int position = 0;
    while ( tmp != tail )
    {
      std::cout << "Position: " << position << ", Data: " << tmp->data << std::endl;
      tmp = tmp->next;
      position++;
    }
    std::cout << "Position: " << position << ", Data: " << tail->data << std::endl;
  }
}
