#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;
typedef int Position;

typedef struct NodeTag {
  ElementType data;
  struct NodeTag *next;
} Node;

typedef Node *List;
typedef Node *PNode;

/*
Initialize an empty list
*/
void makeNull(List *L)
{
  Node *header = (Node *)malloc(sizeof(Node)); 
  header->next = NULL;                         
  (*L) = header;
}

/*
return Number of elements
*/
int len(List L)
{
  int count = 0;
  List P = L;
  while (P != NULL)
  {
    count++;
    P = P->next;
  }
  return count;
}

/*
Check whether the list is empty?
*/
int empty(List L)
{
  return L->next == NULL; 
}

/*
Check whether the list is full?
*/
int fullList(List L)
{ 
}

/*
Traverse the list to print out all elements
*/
void print(List L)
{
  List header = L->next; 
  while (header != NULL)
  {
    printf("%d ", header->data);
    header = header->next;
  }
  printf("\n");
}

/*
Return the element at position p
*/
ElementType getAt(Position p, List L)
{
  int n = len(L); 
  if (p < 1 || p > n)
  {
    printf("Vi tri khong hop le\n");
    return -1;
  }

  List temp = L;
  for (int i = 1; i < p; i++)
  {
    temp = temp->next;
  }
  return temp->data;
}

/*
Return the pointer referring to the ith element
*/
PNode getPosition(Position p, List L)
{
  int n = len(L); 
  if (p < 1 || p > n)
  {
    printf("Vi tri khong hop le\n");
    return NULL;
  }

  PNode newHead = L;
  for (int i = 1; i < p; i++)
  {
    newHead = newHead->next;
  }
  return newHead;
}

/*
Return the pointer referring to the first element of L
*/
PNode first(List L)
{
  List header = L;
  return header;
}

/*
Return the pointer referring to the last element of L
*/
PNode end(List L)
{
  PNode P = L;
  while (P->next != NULL)
  {
    P = P->next;
  }
  return P;
}

/*
Update the element at position p by a new value
*/
void setAt(Position p, ElementType x, List *L)
{
  PNode posi = getPosition(p, *L);
  if (posi != NULL)
  {
    posi->data = x;
  }
}

/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L)
{
  List newNode = (Node *)malloc(sizeof(Node));
  newNode->data = x;
  List temp = *L;
  for (int i = 1; i < p; i++) 
  {
    temp = temp->next;
  }
  if (temp != NULL)
  {
    newNode->next = temp->next;
    temp->next = newNode;
  }
}
/*
Remove and return the element at position p
*/
ElementType popAt(Position p, List *L)
{
  if (*L == NULL || p <= 0)
  {
    printf("vi tri khong hop le");
    return -1; 
  }
  List temp = *L; 
  for (int i = 1; i < p - 1; i++)
  {                   
    temp = temp->next; 
  }
  if (temp->next == NULL)
  {
    return -1; 
  }

  List del = temp->next;
  ElementType data = del->data;
  temp->next = del->next;
  free(del); 
  return data;
}

/*
Insert x to the first position
*/
void insertFirst(ElementType x, List *L)
{
  List newNode = (Node *)malloc(sizeof(Node));
  newNode->data = x;          
  newNode->next = (*L)->next; 
  (*L)->next = newNode;       
}

/*
Remove and return the first element
*/
ElementType popFirst(List *L)
{
  if (*L == NULL)
  {
    return -1;
  }

  List temp = *L; 
  ElementType data = (*L)->next->data;
  *L = (*L)->next; 
  free(temp);
  return data;
}

/*
Append a new element to the list
*/

void append(ElementType x, List *L)
{
  insertAt(len(*L), x, L);
}

/*
Remove and return the last element
*/
ElementType popLast(List *L)
{
  ElementType value;
  PNode posLast = *L;
  while (posLast->next->next != NULL)
  {
    posLast = posLast->next;
  }
  value = posLast->next->data;
  popAt(len(*L), L);
}

/*
Return the position of the first appearance of x in the list
*/
Position locate(ElementType x, List L)
{
  List temp = L->next;
  int count = 1;
  while (temp != NULL)
  {
    if (x == temp->data)
    {
      return count;
    }
    temp = temp->next;
    count++;
  }
  return -1;
}

/*
Return the pointer referring to the next position of i in L
*/
PNode next(Position p, List L)
{
  if (p < 1 || p > len(L))
  {
    printf("Vi tri khong hop le\n");
    return NULL;
  }

  PNode temp = getPosition(p, L); 
  if (temp != NULL)
  {
    return temp->next; 
  }
  return NULL; 
}

/*
Return the pointer referring to the previous position of p in L
*/
PNode previous(Position p, List L)
{
  List temp = L;
  for (int i = 1; i < p - 1; i++)
  {
    temp = temp->next;
  }
  return temp;
}
