#include "ll2.h"

int main()
{
  Node* n1 = new Node();
  n1->data = 2;
  n1->next = 0; // nullptr

  Node* n2 = new Node();
  n2->data = 2;
  n2->next = n1;

  Node* n3 = new Node();
  n3->data = 1;
  n3->next = n2;

  Node* n4 = new Node();
  n4->data = 1;
  n4->next = n3;

  Node* n5 = new Node();
  n5->data = 1;
  n5->next = n4;

  LinkedList* ll = new LinkedList();
  ll->head = n5;
  ll->tail = n1;

  ll->insertAt( 3, 4 );

  //ll->printList();
  
  ll->removeDuplicates();

  ll->printList();

  return 0;
}
