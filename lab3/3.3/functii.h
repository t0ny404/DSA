#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

typedef struct node {
    int data;
    struct node* NxorP;
} Node;

typedef struct list {
    Node* first;
    Node* last;
} List;

Node* XOR (Node* a, Node* b);
List* CreateEmpty();
Node* CreateNode(List* listptr, int data);
void insertAt(List* listptr, int data);
void afis(FILE* fout, List* listptr, int direction);

#endif // FUNCTII_H_INCLUDED
