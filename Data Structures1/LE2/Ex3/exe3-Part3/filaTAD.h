typedef struct queueItems{
    void *data;
    struct queueItems *link;
} QueueItems;

typedef struct headQueue{
    QueueItems *firstNode, *lastNode;
    int size;
} HeadQueue;


void init(HeadQueue *head);
int empty(HeadQueue *head);
void enqueue(HeadQueue *head, void *data);
void dequeue(HeadQueue *head);
int firstElement (HeadQueue *head);
int lastElement(HeadQueue *head);
int size(HeadQueue *head);
void freeEqueue(HeadQueue *head);