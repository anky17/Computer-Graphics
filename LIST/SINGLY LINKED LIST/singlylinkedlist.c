// WAP TO IMPLEMENT THE OPERATION OF SINGLY LINKED LIST USING C.

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void listTraversal(struct node *ptr) {
  while (ptr != NULL) {
    printf("Elements: %d\n", ptr->data);
    ptr = ptr->next;
  }
}

struct node *insertAtFront(struct node *head, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  struct node *p = head;
  ptr->data = data;
  ptr->next = p;
}
struct node *insertatEnd(struct node *head, int data) {
  struct node *p = head;
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = data;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = NULL;
  return head;
}

struct node *insertAtIndex(struct node *head, int data, int index) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  struct node *p = head;
  int i = 0;
  while (i != index - 1) {
    p = p->next;
    i++;
  }
  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;
  return head;
}

struct node *insertatNode(struct node *head, struct node *point, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  struct node *p = head;
  ptr->next = point->next;
  point->next = ptr;
  ptr->data = data;
  return head;
}

struct node *deletefromFront(struct node *head) {
  struct node *ptr = head;
  head = head->next;
  free(ptr);
  return head;
}

struct node *deleteAtIndex(struct node *head, int index) {
  struct node *ptr = head;
  struct node *ptr1 = head->next;
  for (int i = 0; i < index - 1; i++) {
    ptr = ptr->next;
    ptr1 = ptr1->next;
  }
  ptr->next = ptr1->next;
  free(ptr1);
  return head;
}

struct node *deletefromEnd(struct node *head) {
  struct node *ptr = head;
  struct node *ptr1 = head->next;
  while (ptr1->next != NULL) {
    ptr = ptr->next;
    ptr1 = ptr1->next;
  }
  ptr->next = NULL;
  free(ptr1);
  return head;
}

int main() {
  struct node *head;
  struct node *second;
  struct node *third;

  head = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));

  head->data = 7;
  head->next = second;

  second->data = 8;
  second->next = third;

  third->data = 9;
  third->next = NULL;
  // head = insertAtFront(head, 12);
  // head = insertAtIndex(head, 39, 1);
  // head = insertatNode(head, second, 12);
  // head = insertatEnd(head, 90);

  printf("Before Deletion\n");
  listTraversal(head);

  printf("\nAfter Deletion\n");
  // head = deletefromEnd(head);
  head = deleteAtIndex(head, 1);
  listTraversal(head);

  return 0;
}
