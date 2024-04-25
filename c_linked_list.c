#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*Head;

int length(struct Node *p)
{
    int len = 0;
    p = Head;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}

void create(int A[], int n)
{
    struct Node *t, *last;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p) 
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != Head);
    printf("\n");
}

void recursive_display(struct Node *p)
{
    static int flag = 0;
    if (p != Head || flag == 0) {
        flag = 1;
        printf("%d ", p->data);
        recursive_display(p->next);
    }
    flag = 0;
}

void insert(struct Node *p, int x, int pos)
{
    if (pos < 0 || pos > length(Head)) {
        printf("%dOUt of bounds\n");
        return;
    }
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    if (pos == 0) {
        if (Head == NULL) {
            Head = t;
            Head->next = Head;
        } else {
            while (p->next != Head) p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    } else {
        for (int i = 0; i < pos-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;            
    }
}

int delete(struct Node *p, int pos)
{

    if (pos < 0 || pos > length(Head))
        return -1;

    if (pos == 1) {
        while (p->next != Head) p = p->next;
        int x = Head->data;
        if (Head == p) {
            free(Head);
            Head = NULL;
        } else {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
        return x;
    } else {
        for (int i = 0; i < pos-2; i++)
        {
            p=p->next;
        }
        struct Node *q = p->next;
        p->next = q->next;
        int x = q->data;
        free(q);
        return x;
    }
}




int main() {

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    // display(Head);
    insert(Head, 10, 2);
    insert(Head, 7, 0);
    delete(Head, 1);
    delete(Head, 3);
    recursive_display(Head);


    return 0;
}