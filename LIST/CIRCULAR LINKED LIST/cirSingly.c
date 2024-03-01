// WAP TO IMPLEMENT ALL THE OPERATION OF CIRCULAR SINGLY LINKED LIST.

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void traverse(struct node *last) {
  struct node *p;
  p = last->next;

  do {
    printf("Element: %d\n", p->data);
    p = p->next;
  } while (p != last->next);
}

// add node to the front
struct node *insertAtFront(struct node *last, int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;

  // store the address of the current first node in the newNode to make it the
  // updated first node
  newNode->next = last->next;

  // make newNode as first by storing the address of newNode in the last node
  last->next = newNode;

  return last;
}
// add node to the end
struct node *insertAtEnd(struct node *last, int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;

  // store the address of the first node to next of newNode
  newNode->next = last->next;

  // point the last node to the newNode to make it the new last node
  last->next = newNode;

  // make newNode as the last node
  last = newNode;

  return last;
}
// insert node after a specific node
struct node *addAfter(struct node *last, int data, int item) {
  struct node *newNode, *p;

  p = last->next;
  do {
    // if the item is found, place newNode after it
    if (p->data == item) {
      // allocate memory to the new node
      newNode = (struct node *)malloc(sizeof(struct node));

      // add data to the node
      newNode->data = data;

      // make the next of the current node as the next of newNode
      newNode->next = p->next;

      // put newNode to the next of p
      p->next = newNode;

      // if p is the last node, make newNode as the last node
      if (p == last) last = newNode;
      return last;
      p = p->next;
    }
  } while (p != last->next);

  return last;
}

int main() {
  struct node *last;
  struct node *first = NULL;
  struct node *second = NULL;
  struct node *third = NULL;

  first = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));

  first->data = 7;
  first->next = second;

  second->data = 8;
  second->next = third;

  third->data = 9;
  third->next = first;

  last = third;
  last = insertAtFront(last, 90);
  last = insertAtEnd(last, 100);
  traverse(last);

  return 0;
}