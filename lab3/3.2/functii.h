#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

typedef struct node {

    char word[255];
    int apariti;
    struct node* next;
    struct node* prev;

} Node;

typedef struct list {

    int count;
    Node* first;
    Node* last;

} List;

List* CreateEmpty();
Node* CreateNode(char w[255]);
void insertInOrder(List* listptr, char w[255]);
void ascending(List* First, FILE* fout);
void descending(List* First, FILE* fout);

#endif // FUNCTII_H_INCLUDED
