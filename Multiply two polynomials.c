#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "defination.h"
int main(void)
{
    List L1 = MakeEmpty(L1);
    List L2 = MakeEmpty(L2);
    List L3 = MakeEmpty(L3);
    Item input, new;
    int n1 = 0;
    int n2 = 0;
    puts("enter L1(q to end):");
    while (scanf("%d", &input.num) == 1 && !IsFull(L1))
    {
        getchar();
        input.exp = n1++;
        Insert(input, L1, NULL);
    }
    getchar();
    Func(L1);
    printf("\n");
    puts("enter L2(q to end):");
    while (scanf("%d", &input.num) == 1 && !IsFull(L2))
    {
        getchar();
        input.exp = n2++;
        Insert(input, L2, NULL);
    }
    Func(L2);
    printf("\n");
    Node * scan1 = ((Node*) L1)->next;
    Node * scan2 = ((Node*) L2)->next;
    for (int i = 0; i <= n1 + n2 - 2; i++)
    {
        new.num = 0;
        new.exp = i;
        Insert(new, L3, NULL);
    }
    Node * head = ((Node*) L3)->next;
    Node * add;
    for (int i = 0; i < n1; i++)
    {
        add = head;
        for (int j = 0; j < n2; j++)
        {
            add->item.num += (scan1->item.num) * (scan2->item.num);
            add = add->next;
            scan2 = scan2->next;
        }
        scan1 = scan1->next;
        scan2 = ((Node*) L2)->next;
        head = head->next;
    }
    
    Func(L3);
    printf("\n");
    DeleteList(L1);
    DeleteList(L2);
    DeleteList(L3);
}