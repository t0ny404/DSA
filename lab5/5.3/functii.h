#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

#define LEFT 1
#define RIGHT 2

typedef struct node {

    char name[500];
    float price;
    int amount;
    long dateOfManufacturing;
    long dateOfExpiration;
    struct node* left;
    struct node* right;

} BSTNode;

void preorder( BSTNode* p, int level, FILE* fout );
void inorder( BSTNode* p, int level, FILE* fout );
void postorder( BSTNode* p, int level, FILE* fout );
BSTNode* Insert( BSTNode* root, BSTNode* p, FILE* fout );
BSTNode* deleteNode( BSTNode* root, char* key, FILE* fout );
BSTNode* Find( BSTNode* root, char* key, FILE* fout );

#endif // FUNCTII_H_INCLUDED
