#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

#define LEFT 1
#define RIGHT 2

typedef struct node {

    char key;
    struct node* left;
    struct node* right;

} BSTNode;

void preorder( BSTNode* p, int level, FILE* fout );
void inorder( BSTNode* p, int level, FILE* fout );
void postorder( BSTNode* p, int level, FILE* fout );
BSTNode* Insert( BSTNode* root, char key, FILE* fout );
BSTNode* deleteNode( BSTNode*, char key, FILE* fout );
void Find( BSTNode* root, char key, FILE* fout );
BSTNode* findMin( BSTNode* node );
BSTNode* findMax( BSTNode* node );


#endif // FUNCTII_H_INCLUDED
