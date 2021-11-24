#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int id;
    struct node*left,*right;

} NodeT;

int maxim;
int found = 0;
int next;

NodeT* createBinTree( FILE* fin )
{
    NodeT* p;
    int id;
    fscanf( fin, "%d", &id);
    if ( id == 0 )
        return NULL;
    else
    {
        p = (NodeT*)malloc(sizeof( NodeT ));
        if( p == NULL )
           { printf( "Out of space in createBinTree" ); return NULL; }
        p->id = id;
        p->left = createBinTree( fin );
        p->right = createBinTree( fin );
    }
    return p;
}

void postorder( NodeT* p, int level, FILE* fout )
{
    if( p != NULL )
    {
        postorder( p->left, level + 1, fout );
        postorder( p->right, level + 1, fout );
        for( int i = 0; i <= level; i++ )
            fprintf( fout, " ");
        fprintf( fout, "%d\n", p->id );
    }
}

void maxNode( NodeT* p, int level )
{
    if( p != NULL )
    {
        maxNode( p->left, level + 1 );
        maxNode( p->right, level + 1 );

        if( p->id > maxim )
            maxim = p->id;
    }
}

void postorderSearch( NodeT* p, int level, int id )
{
    if( p != NULL )
    {
        postorderSearch( p->left, level + 1, id );
        postorderSearch( p->right, level + 1, id );

        if( p->id == id )
            found = 1;
    }
}

int height( NodeT* tree )
{
    int left, right;

    if( !tree )
        return 0;

    left = height( tree->left );
    right = height( tree->right );

    if( left > right )
        return left + 1;
    else
        return right + 1;
}

void succesor( NodeT* p, int level, int id )
{
    if( p != NULL )
    {
        succesor( p->left, level + 1, id );
        succesor( p->right, level + 1, id );

        if( p->left->id == id || p->right->id == id )
            next = p->id;
    }
}

int main()
{
    FILE* fin = fopen( "input.txt", "r" );

//pune valori numerice in fiecare nod al arborelui, din fisier
    NodeT* root = createBinTree( fin );

//afisare arbore in postordine
    postorder( root, 0, stdout );

//cauta un nod in arbore
    int seek;
    printf( "\nCauta:" );
    scanf( "%d", &seek );
    postorderSearch( root, 0, seek );
    if( found == 1 )
        printf( "Am gasit %d\n", seek );
    else printf( "Ia-l de unde nu-i!?!?!\n" );

//inaltimea arborelui
    int h = height( root ) - 1;
    printf( "height: %d\n", h );

//nodul cu valoarea maxima
    maxim = root->id;
    maxNode( root, 0 );
    printf( "%d este nodul cu valoarea maxima\n", maxim );

//succesorul
    int nod;
    printf( "Succesorul nodului " );
    scanf( "%d", &nod );
    succesor( root, 0, nod );
    printf( " este %d\n", next );

    fclose( fin );
    return 0;
}
