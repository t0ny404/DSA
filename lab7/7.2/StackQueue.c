#include <stdio.h>
#include <stdlib.h>
#include "StackQueue.h"

//stack

Stack* createStack()
{
    Stack* stack = ( Stack* )malloc( sizeof( Stack ) );
    stack->top = -1;
    stack->capacity = 1;
    stack->mem = ( int* )malloc( stack->capacity * sizeof( int ) );

    return stack;
}

int isEmptyS( Stack* stack )
{
    return stack->top == -1;
}

void push( Stack* stack, int elem )
{
    stack->mem = ( int* )realloc( stack->mem, ++stack->capacity * sizeof( int ) );
    stack->mem[++stack->top] = elem;
}

int pop( Stack* stack )
{
    if ( isEmptyS( stack ) )
        return -1;
    return stack->mem[stack->top--];
}

int top( Stack* stack )
{
    return stack->mem[stack->top];
}

//queue

Queue* createQueue()
{
    Queue* queue = ( Queue* ) malloc( sizeof( Queue ) );
    queue->capacity = 1;
    queue->front = queue->rear = queue->size = 0;
    queue->mem = ( int* ) malloc( sizeof( int ) );
    return queue;
}

int isEmptyQ( Queue* queue )
{  return ( queue->size == 0 ); }

void enqueue( Queue* queue, int elem )
{
    queue->mem = ( int* )realloc( queue->mem, ++queue->capacity * sizeof( int ) );
    queue->mem[queue->rear++] = elem;
    queue->size++;
}

int dequeue( Queue* queue )
{
    if ( isEmptyQ( queue ) )
        return -1;

    int elem = queue->mem[queue->front];
    queue->front++;
    queue->size--;

    return elem;
}
