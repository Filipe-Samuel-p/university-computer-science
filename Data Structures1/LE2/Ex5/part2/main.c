#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    void *data;
    struct node *link;
} Node;

typedef struct{
    int count;
    Node *head;
    Node *pos;
    Node *tail;
    int (*compare)(void *arg1, void *arg2);
} List;

List *createList(int(*compare) (void *arg1, void *arg2)){ //Esta funcao recebe um ponteiro para uma função de comparação como argumento. 
                                                            //Essa função de comparação é usada para comparar elementos na lista.
    List *list = (List*)malloc(sizeof(List));
    if(list){
        list->head = NULL;
        list->pos = NULL;
        list->tail = NULL;
        list->count = 0;
        list->compare = compare;
    }
    return list;
}

int addNode (List *head, void *data){
    bool found,sucess;
    Node;
}


int main(void){





    return 0;
}