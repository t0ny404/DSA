#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

typedef struct node {

    int key;
    int next;
    int count;

} Node;

typedef struct list {

    unsigned int capacity;
    Node* data;

} List;

List* CreateList(int size);
int keepLoop(int j, int size);
int delet(List* listptr, int gkey);
int winner(List* listptr, int n);

#endif // FUNCTII_H_INCLUDED
