#ifndef FUNCTII2_H_INCLUDED
#define FUNCTII2_H_INCLUDED

typedef struct Node {
    char operand;
    struct Node* next;
} List;

typedef struct node {
    char op;
    struct node* left;
    struct node* right;
} Tree;


Tree* createBinTree();
void postfix( Tree* p );
void inorder( Tree* p, int level );


#endif // FUNCTII2_H_INCLUDED
