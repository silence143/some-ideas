#ifndef DEFINATION_H_
#define DEFINATION_H_
#include <stdbool.h>
typedef struct list
{
    int num;
    int exp;
}Item;
typedef struct node
{
    Item item;
    struct node * next;
}Node;
typedef struct Node * List;

List MakeEmpty(List L);
bool IsEmpty(List L);
bool IsFull(List L);
bool IsLast(List P, List L);
Node * FindExp(Item i, List L);
void Delete(Item i, List L);
Node * FindExpPrevious(Item i, List L);
void Insert(Item i, List L, List P);
void DeleteList(List L);
void Func(List L);

List MakeEmpty(List L)
{ 
    L = (List)malloc(sizeof(Node));
    ((Node*) L)->next = NULL;
    return L;
}

bool IsEmpty(List L)
{    
    return ((Node*) L)->next == NULL ? true : false;  
}

bool IsFull(List L)
{
    Node * temp;
    bool full;
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
        full = true;
    else
        full = false;
    free(temp); 
    return full;
}

bool IsLast(List P, List L)
{
    return ((Node*) P)->next == NULL ? true : false;
}

Node * FindExp(Item i, List L)
{
    Node * scan = (Node*) L;
    while (scan != NULL)
    {
        if (scan->item.exp == i.exp)
            return scan;
        scan = scan->next;
    }  
    return scan;
}

Node * FindExpPrevious(Item i, List L)
{
    Node * scan = (Node*) L;
    while (scan->next != NULL)
    {
        if (scan->next->item.num == i.num)
            return scan;
        scan = scan->next;
    }
    return scan;
}

void Insert(Item i, List L, List P)
{
    Node * pnew;
    Node * temp;
    pnew = (Node*)malloc(sizeof(Node));
    if (pnew == NULL)
    {    
        fprintf(stderr, "wrong!");
        exit(1);
    }
    if (IsEmpty(L) || P == NULL)
    {
        pnew->item = i;
        pnew->next = NULL;
        temp = ((Node*) L);
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = pnew;
    }
    else
    {
        pnew->item = i;
        pnew->next = ((Node*) P)->next;
        ((Node*) P)->next = pnew;
    }
}

void Delete(Item i, List L)
{
    Node * P = FindExpPrevious(i, L);
    Node * temp;
    temp = P->next;
    P->next = temp->next;
    free(temp);
}

void DeleteList(List L)
{
    if (IsEmpty(L))
    {    
        fprintf(stderr, "list is empty!");
        exit(1);
    }
    Node * temp = ((Node*) L);
    Node * P = ((Node*) L);
    while (temp != NULL)
    { 
        temp = temp->next;
        free(P);
        P = temp; 
    }
}

void Func(List L)
{
    Node * temp = ((Node*) L)->next;
    while (temp != NULL)
    {
        printf("%d\t", temp->item.num);
        temp = temp->next;
    }
    
}
#endif

