#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<array>
using namespace std;

struct node
{
    int info;
    struct node *next;
};

void Traversal(struct node *start)
{
    struct node *ptr = start;
    do
    {
        cout << ptr -> info << " ";
        ptr = ptr -> next;
    }
    while(ptr != start);
    cout << endl;
}

void searchingAnEle(struct node *start, int data)
{
    struct node *ptr = start;
    int pos = 1;
    do
    {
        if(ptr -> info == data)
        {
            cout << "Element " << data << " found in position " << pos << endl;
        }
        ptr = ptr -> next;
        pos++;
    }
    while(ptr != start);
}

struct node *insertAtEmp(struct node *start, int data)
{
    struct node *ptr;
    ptr = new(struct node);
    ptr -> info = data;
    start = ptr;
    start -> next = start;
    return start;
}

struct node *insertAtBeg(struct node *start, int data)
{
    struct node *ptr, *p;
    ptr = new(struct node);
    ptr -> info = data;
    p = start -> next;
    while(p -> next != start)
    {
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = start;
    start = ptr;
    return start;
}

struct node *insertAtEnd(struct node *start, int data)
{
    struct node *ptr, *p;
    p = start;
    ptr = new(struct node);
    ptr -> info = data;
    while(p -> next != start)
    {
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = start;
    return start;
}

struct node *insertAtBetAft(struct node *start, int data, int item)
{
    struct node *ptr, *p;
    p = start;
    ptr = new(struct node);
    while(p -> next != start)
    {
        if(p -> info == item)
        {
            ptr -> info = data;
            ptr -> next = p -> next;
            p -> next = ptr;
            return start;
        }
        p = p -> next;
    }
    cout << "The item " << item << " not present in the list." << endl;
    return start;
}

struct node *insertAtBetBef(struct node *start, int data, int item)
{
    struct node *ptr, *p;
    p = start;
    ptr = new(struct node);
    while(p -> next != start)
    {
        if(p -> next -> info == item)
        {
            ptr -> info = data;
            ptr -> next = p -> next;
            p -> next = ptr;
            return start;
        }
        p = p -> next;
    }
    cout << "The item " << item << " not present in the list." << endl;
    return start;
}

struct node *insertAtBetPos(struct node *start, int data, int pos)
{
    struct node *ptr, *p;
    p = start;
    ptr = new(struct node);
    ptr -> info = data;
    for(int i = 1; i < pos - 1 && p -> next != start; i++)
    {
        p = p -> next;
    }
    if(p -> next == start)
    {
        cout << "There is less than " << pos << " elements." << endl;
    }
    else
    {
        ptr -> next = p -> next;
        p -> next = ptr;
        return start;
    }
}

struct node *create_list(struct node *start)
{
    int n, p;
    cout << "How many element you want to add? ";
    cin >> n;
    start = NULL;
    if(n == 0)
    {
        return start;
    }
    cout << "Enter the first element : ";
    cin >> p;
    start = insertAtEmp(start, p);
    cout << "Enter the next element : ";
    for(int i = 2; i <= n; i++)
    {
        cin >> p;
        start = insertAtEnd(start, p);
    }
    cout << "The create list is : " << endl;
    return start;
}

struct node *del(struct node *start, int item) // There was en error in deletation.
{
    struct node *temp, *p;
    if(start == NULL)
    {
        cout << "This is empty list." << endl;
        return start;
    }
    p = start;
    if(p -> info == item)
    {
        while(p -> next != start)
        {
            p = p -> next;
        }
        p -> next = start -> next;
        free(start);
        start = p -> next;
        return start;
    }
    p = start -> next;
    while(p -> next != start)
    {INDX( 	 {�o           (   �  �         e                    7    h � ~     �5    u >���&��>���&��>���&��>���&���      �              1 - M i c r o s o f t   A u t h e n t i c a t i o n . l o g    7    h p Z     �5    u >���&��>���&��>���&��>���&���      �              1 - M I C R ~ 1 . L O G       47     � l     �5    u >���&���T��&���T��&���T��&��(       &               2 - A u t o   R e n a m e   T a g . l o g     47     p Z     �5    u >���&���T��&���T��&���T��&��(      &               2 - A U T O ~ 1 . L O G       d7    � h T     �5    u >���&��#[��&��#[��&��#[��&��0       +               	3 - G i t . l o g     �7    L � x     �5    u �G��&��͇\�&��͇\�&��͇\�&��       �              4 - G i t H u b   A u t h e n t i c a t i o n . l o g �7    L p Z     �5    u �G��&��͇\�&��͇\�&��͇\�&��       �              4 - G I T H ~ 1 . L O G       �7    , � v     �5    u W!�&��W!�&��W!�&��W!�&��                        5 - J S O N   L a n g u a g    S e r v e r . l o g   �7    , p Z     �5    u W!�&��W!�&��W!�&��W!�&��                        5 - J S O N ~ 1 . L O G       C8    4 p ^     �5    u -!��&��-!��&��-!��&��-!��&��p       n               6 - P r e t t i e r . l o g   C8    4 p Z     �5    u -!��&��-!��&��-!��&��-!��&��p       n               6 - P R E T ~ 1 . L O G       S8    & h V     �5    u -!��&��-!��&��-!��&��-!��&��                        
7 - C o d e . l o g                                                                                                                                                                                                                                                                                                                                                    