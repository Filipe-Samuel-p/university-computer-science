#include <stdio.h>

typedef struct node
{
    void *dtaptr;
    struct node *link;
} NODE;

NODE *createNode (void *intemptr){
    NODE *nodeptr;
    nodeptr = (NODE*)malloc(sizeof(NODE));
    nodeptr -> dataptr = intemptr;
    
}


int main(void) {







    return 0;
}