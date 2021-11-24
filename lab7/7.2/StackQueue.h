#ifndef STACKQUEUE_H_INCLUDED
#define STACKQUEUE_H_INCLUDED

//stack

typedef struct {

    int top;
    unsigned capacity;
    int* mem;

}Stack;

Stack* createStack();
int isEmptyS( Stack* );
void push( Stack*, int );
int pop( Stack* );
int top( Stack* );

//queue

typedef struct {

    int front, rear, size;
    unsigned capacity;
    int* mem;

}Queue;

Queue* createQueue();
int isEmptyQ( Queue* );
void enqueue( Queue*, int );
int dequeue( Queue* );

#endif // STACKQUEUE_H_INCLUDED
