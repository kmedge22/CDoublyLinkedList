#include <stdio.h>
#include <MacTypes.h>
#include <stdlib.h>
#include <assert.h>
#include <printf.h>

/*
 * Queue
 *      head
 *          points to first QueueNode
 *      tail
 *          points to last QueueNode
 *       both have pointers to queue nodes
 *              Queue Nodes
 *              next()
 *              data
 *              prev() //need to implement
 * FIFO
 */

struct queuenode_t{
    struct queuenode_t *next;
    struct queuenode_t *prev;
    int data;
};

typedef struct {
    int    key;
    int    value;
} data_t;


//char *toString(int data);

/*Create node constructor
//alias for a type queuenode_t, so that you may call it QueueNode
*/
typedef struct queue_node_t{
    int data;
    struct queue_node_t *next;
    struct queue_node_t *prev;

} QueueNode;


/*Create Queue "constructor"
can define and give alias at the same time
 */
typedef struct queue_t{
    QueueNode *head;
    QueueNode *tail;
} Queue;


void initQueue(Queue *self ){
    if (self == NULL)
        return;
    //USE arrow instead of self.head bc it is a pointer
    self->head = NULL;
    self->tail = NULL;

}
void printQ(Queue *self) {
    QueueNode* temp = self -> head;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/*
 * Add a node to end of list
 */
void enQueue(Queue *self, int data){
    QueueNode *p;

    //for sanity to make sure things are working as they should
    if (self == NULL)
        return;

    //need to create a new node
    //calloc allocates memory 1 of sizeof() bites and returns (QueueNode* cast)
    //p is a pointer to a new unattached queuenode that has a next and a data attribute
    p = (QueueNode*)calloc(1, sizeof(QueueNode));

    //now I need to assign data from parameter to data attribute.
    p -> data = data;
    if(self->head == NULL) {
        //Queue is empty
        self -> head = self -> tail = p;
    }
    else{
        //assin the tail node's next to new node before you move the tail
        self -> tail -> next = p;
        //adding myself to assign new node (p)'s prev to the current tail
        p -> prev = self -> tail;
        //
        //reassigned tail (in class)
        self -> tail = p;
    }
}

/*
 * Return the data from the front of the list and remove the node associated with it
 */
data_t *deQueue(Queue *self){
    int q;

    //for sanity to make sure things are working as they should
    if (self == NULL)
        return NULL;

    if(self->head == NULL) {
        //Queue is empty
        return NULL;
    }



    //now I need to identify the data of the first node.
    q  = self -> head -> data;

    //assn new head
    self -> head = self -> head ->next;
    //assin the head to self.head.prev to null
    self -> head -> prev -> next = NULL;
    //assn current heads prev to null
    self -> head ->prev = NULL;

    return (data_t *) q;


}

QueueNode *frontNode(Queue *self){

    //for sanity to make sure things are working as they should
    if (self == NULL)
        return NULL;

    if(self->head == NULL) {
        //Queue is empty
        return NULL;
    }

    return self->head;

}

data_t *frontValue(Queue *self){
    int q;

    //for sanity to make sure things are working as they should
    if (self == NULL)
        return NULL;

    if(self->head == NULL) {
        //Queue is empty
        return NULL;
    }

    //identify the data of the first node.
//    q  = self -> head -> data;
    q = frontNode(self)->data;
    printf("The front value is: %i",q);
    return (data_t *) q;

}

///*remove the QueueNode pointed to by p
// */
//void removeNode(Queue *self, QueueNode *p){
//    bool found;
//    //for sanity to make sure things are working as they should
//    if (self == NULL)
//        return;
//
//    //start at self.head and check if self.head.data matches p.data
//    if (self ->head->data == p->data){
//        found = true;
//
//    }
//}

void removeNode(Queue *self, QueueNode *p){}\

QueueNode *findNode (Queue *self, data_t *d) {
    QueueNode* temp = self -> head;
    while(temp->data != d->key) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}


int main(){
    Queue myQueue;
    initQueue(&myQueue);

    enQueue(&myQueue, 5);
    enQueue(&myQueue, 10);
    enQueue(&myQueue, 15);

    printQ(&myQueue);
    deQueue(&myQueue);
    printQ(&myQueue);

    frontValue(&myQueue);

}



//char *toString(int data) {
//    static char result[BUFSIZ];
//
//    if (data==NULL)
//        sprintf()



//}
