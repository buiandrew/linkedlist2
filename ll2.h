#include <iostream>

struct Node
{
  /* Nodes are "dumb" and have no member functions */
  int data;
  Node* next;
};

struct LinkedList
{
  /* Data Members */
  Node* head;
  Node* tail;

  /* Destructor */
  ~LinkedList() { clear(); }

  /* Member Functions */
  bool empty();
  // Returns 1 for an empty list, 0 for a non empty list.

  void prepend( int data );
  // Creates a node with data 'data' and adds it to the beginning of
  // the LinkedList.

  void append( int data );
  // Adds a Node with the desired data at the end of the LinkedList
  
  void insertAt( int data, unsigned int const position );
  // Inserts a Node with data at the desired position.

  int decaudate();
  // Deletes the tail Node and returns its data.

  int decapitate();
  // Deletes the head Node and returns its data.

  int removeAt( unsigned int const position );
  // Removes the Node at position and returns its data. If position
  // is out of index, removes the tail Node.

  void clear();
  // Removes all elements from the LinkedList.

  int itemAtHead();
  // Returns data in head Node.

  int itemAtTail();
  // Returns data in tail Node.

  int itemAt( unsigned int const position );
  // Returns data from the Node at the desired position.

  bool contains( int value );
  // Returns 1 if the LinkedList contains the value, 0 if it doesnt.

  unsigned int length();
  // Returns the length of the LinkedList.

  void removeDuplicates();
  // Removes Nodes with duplicate data.

  void printList();
  // Prints the LinkedList.
};
