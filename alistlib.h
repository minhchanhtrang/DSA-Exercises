#include <stdio.h>
#include <stdlib.h>

#define MaxLength 100    //maximum size of list

typedef int ElementType;   // the element type of list
typedef int Position;   // the position type of elements

typedef struct {
    ElementType Elements[MaxLength];   // mang bao gom cac phan tu cua danh sach
    Position Last;   //do dai cua danh sach
} List;

// Initialize an empty list
void makeNull(List *L) { 
    L->Last = 0;
}

// Number of elements
int Len(List L) {  
    return L.Last;
}

// Check whether the list is empty?
int empty(List L) {
    return L.Last == 0;
}

// Check whether the list is full?
int fullList(List L) {
    return L.Last == MaxLength;
}

// Return the first position in L
Position first(List L) {
    return 1;
}

// Return the end position in L
Position endList(List L) {
    return L.Last + 1;
}

// Return the next position of p in L
Position next(Position P, List L) {
    return P + 1;
}

// Return the element at position p
ElementType getAt(Position P, List L) {
    return L.Elements[P - 1];
}

// Traverse the list to print out all elements
void print(List L) {
    if (empty(L)) {
        printf("List is empty!\n");
        return;
    }
    if (fullList(L)) {
        printf("List is full!\n");
        return;
    }
    int i = first(L);
    for (i ; i < endList(L); i++) {
        printf("%d ", L.Elements[i - 1]);
    }
    printf("\n");
}

// Update the element at position p by a new value x
void setAt(Position P, ElementType x, List *L) {
    if (P < 1 || P > Len(*L)) {
        printf("Error: Invalid position!\n");
        return;
    }
    L->Elements[P - 1] = x;
}

// Insert x at position p
void insertAt(Position P, ElementType X, List *L) {
    if (fullList(*L)) {
        printf("List is full!\n");
        return;
    }
    if (P < 1 || P > L->Last + 1) {
        printf("Error: Invalid position!\n");
        return;
    }
    int i = L->Last;
    for (i; i >= P; i--) {
        L->Elements[i] = L->Elements[i - 1];
    }
    L->Elements[P - 1] = X;
    L->Last++;
}

// Remove and return the element at position p
ElementType popAt(Position P, List *L) {
    if (empty(*L)) {
        printf("List is empty!\n");
        return -1; 
    }
    if (P < 1 || P > L->Last) {
        printf("Error: Invalid position!\n");
        return -1; 
    }
    ElementType a = L->Elements[P - 1];
    int i = P - 1;
    for ( i ; i < L->Last - 1; i++) {
        L->Elements[i] = L->Elements[i + 1];
    }
    L->Last--;
    return a;
}

// 	Insert x to the first position
int insertFirst(ElementType x, List *L) {
    if (fullList(*L)) {
        printf("List is full!\n");
        return 0;
    }
    insertAt(first(*L), x, L);
    return 1;
}

// 	Remove and return the first element
void popFirst(List *L) {
    popAt(first(*L), L);
}

// Append a new element to the list
void append(ElementType x, List *L) {
    if (fullList(*L)) {
        printf("List is full!\n");
        return;
    }
    L->Elements[L->Last] = x;
    L->Last++;
}

// Remove and return the last element
void popLast(List *L) {
    popAt(L->Last, L);
}

// Return the position of the first appearance of x in the list
Position locate(ElementType x, List L) {
	Position p = first(L);
    for (p ; p < endList(L); p++) {
        if (L.Elements[p - 1] == x) {
            return p;
        }
    }
    return -1; // neu khong tim thay
}

// Return the previous position of p in L
Position previous(Position p, List L) {
    return p - 1;
}

// Sap xep theo thu tu tang dan
void sort(List *L) {
	Position p = first(*L);
    for ( p; p < endList(*L) - 1; p = next(p, *L)) {
    	Position q = next(p, *L);
        for (q ; q < endList(*L); q = next(q, *L)) {
            if (getAt(p, *L) > getAt(q, *L)) {
                ElementType temp = L->Elements[p - 1];
                L->Elements[p - 1] = L->Elements[q - 1];
                L->Elements[q - 1] = temp;
            }
        }
    }
}
