#include <iostream>
using namespace std;

struct LinkList{
    int data;
    struct LinkList *next;
};

void InsertLinkList(struct LinkList **head, int data, int position/*place to insert*/)
{
    struct LinkList *newNode,*p,*q;
    int k=1;
    newNode = new LinkList;
    newNode->data = data;
    p = *head;
    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        while ((p!=NULL) && (k<position))
        {
            k++;
            q=p;
            p=p->next;
        }
        
        if ((k!=position) || (p == NULL))
        {
            cout << "No more nodes left" << endl;
            return;
        }
        
        if (p != NULL)
        {
            newNode->next = p;
            q->next = newNode;
        }
    }
}

void PrintLinkList(struct LinkList *head)
{
    struct LinkList *q;
    q = head;
    int count = 0;
    while(q!=NULL)
    {
        cout << "LL[" << count++ << "]" << q->data << " ";
        q = q->next;
    }
    cout << endl;
}

struct LinkList * ReverseLinkListIter(struct LinkList **head)
{
    struct LinkList *temp = NULL;
    struct LinkList *nextNode;
    while(*head)
    {
        nextNode = (*head)->next;
        (*head)->next = temp;
        temp = *head;
        *head = nextNode;
    }
    *head = temp;
    return temp;
}

struct LinkList * ReverseLinkListRec(struct LinkList *head)
{
    if (!head)
       return NULL;
    if (head->next == NULL)
       return head;
    struct LinkList *secondList = head->next;
    head->next = NULL;
    
    struct LinkList *recList = ReverseLinkListRec(secondList);
    secondList->next = head;
    return recList;
}

int main() {
	struct LinkList *head;
	InsertLinkList(&head,1,1);
	InsertLinkList(&head,2,1);
	InsertLinkList(&head,3,1);
	InsertLinkList(&head,4,1);
	PrintLinkList(head);
	ReverseLinkListIter(&head);
	PrintLinkList(head);
	return 0;
}
