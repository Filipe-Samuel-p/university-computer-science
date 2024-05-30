#include "implemetation.c"

typedef struct stack{
    void *data;
    struct node *link;
} StackElements;

typedef struct{ 
    int count;
    StackElements *top;
} HeadStack;


int empty(HeadStack *head);
bool push(HeadStack *head, void *data);
void *pop(HeadStack *head);
void *elementTop(HeadStack *head);
bool fullStack(HeadStack *head);
int totalElements(HeadStack *head);
HeadStack *freeStack(HeadStack *head);