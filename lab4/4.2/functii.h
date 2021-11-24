#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

typedef struct node {

    char id;
    struct node*left,*right;

} NodeT;

void fatalError( const char* msg );
void printTree( NodeT* root, FILE* fout);
void preorder( NodeT* p, int level, FILE* fout );
void inorder( NodeT* p, int level, FILE* fout );
void postorder( NodeT* p, int level, FILE* fout );
NodeT* createBinTree( FILE* fin );
NodeT* interchange( NodeT* tree, char nodeID );
int leaves( NodeT* tree );
int height( NodeT* tree );

#endif // FUNCTII_H_INCLUDED
