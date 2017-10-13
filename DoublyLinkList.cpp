#include <iostream>
using namespace std;

struct DLList{
    int data;
    struct DLList *next;
    struct DLList *prev;
};

void InsertDLList(struct DLList **head, int data, int position/*place to insert*/)
{
    struct DLList *newNode,*p;
    int k=1;
    newNode = new DLList;
    newNode->data = data;
    p = *head;
    if (position == 1)
    {
        newNode->next = *head;
        if (*head)
            (*head)->prev = newNode;
        *head = newNode;
        newNode->prev = NULL;
    }
    else
    {
#if 0
        while ((p!=NULL) && (k<position))
        {
            k++;
            p=p->next;
        }
        
        if (k!=position)
        {
            cout << "No more nodes left";
            return;
        }
        
        if (p!=NULL)
        {
            newNode->prev = p->prev;
            (p->prev)->next = newNode;
            p->prev = newNode;
        }
        newNode->next = p;
    
#endif
    while ((p->next!=NULL) && (k < position-1))
    {
        k++;
        p=p->next;
    }
    
    if (k!=position)
    {
        cout << "No more nodes left";
        return;
    }
    
    newNode->next = p->next;
    newNode->prev = p;
    
    if (p->next)
    {
        (p->next)->prev = newNode;
    }
    
    p->next = newNode;
    }   
}

void printDLList(struct DLList *head)
{
    struct DLList *q;
    q = head;
    while(q!=NULL)
    {
        cout << q->data << " ";
        q = q->next;
    }
}

int main() {
	// your code goes here
	struct DLList *head;
	InsertDLList(&head,1,1);
	InsertDLList(&head,2,1);
	InsertDLList(&head,3,1);
	InsertDLList(&head,4,4);
	printDLList(head);
	return 0;
}
