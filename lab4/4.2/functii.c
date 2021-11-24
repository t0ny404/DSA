#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

void fatalError( const char* msg )
{
    printf( msg );
    printf( "\n" );
    exit ( 1 );
}

void printTree( NodeT* root, FILE* fout ){

    fprintf( fout, "\nPreorder listing\n" );
    preorder( root, 0, fout );

    fprintf( fout, "\nInorder listing\n" );
    inorder( root, 0, fout );

    fprintf( fout, "\nPostorder listing\n" );
    postorder( root, 0, fout );
}

void preorder( NodeT* p, int level, FILE* fout )
{
    if(p != NULL)
    {
        for( int i = 0; i <= level; i++ )
            fprintf( fout, " " );
        fprintf( fout, "%c\n", p->id );
        preorder( p->left, level + 1, fout );
        preorder( p->right, level + 1, fout );
    }
}

void inorder( NodeT* p, int level, FILE* fout )
{
    if( p != NULL )
    {
        inorder( p->left, level + 1, fout );
        for( int i = 0; i <= level; i++ )
            fprintf( fout, " " );
        fprintf( fout, "%c\n", p->id );
        inorder( p->right, level + 1, fout );
    }
}

void postorder( NodeT* p, int level, FILE* fout )
{
    if( p != NULL )
    {
        postorder( p->left, level + 1, fout );
        postorder( p->right, level + 1, fout );
        for( int i = 0; i <= level; i++ )
            fprintf( fout, " ");
        fprintf( fout, "%c\n", p->id );
    }
}

NodeT* createBinTree( FILE* fin )
{
    NodeT* p;
    char c;
    fscanf( fin, "%c", &c);
    if ( c == '*' )
        return NULL;
    else
    {
        p = (NodeT*)malloc(sizeof( NodeT ));
        if( p == NULL )
            fatalError( "Out of space in createBinTree" );
        p->id = c;
        p->left = createBinTree( fin );
        p->right = createBinTree( fin );
    }
    return p;
}

NodeT* interchange( NodeT* tree, char nodeID )
{
    if( tree )
    {
        if( nodeID == tree->id )
        {
            NodeT** p = (NodeT**)malloc(sizeof(NodeT));
            if( !p )
                fatalError( "Out of space in interchange()" );

            *p = tree->left;
            tree->left = tree->right;
            tree->right = *p;

            free(p);
            return tree;
        }
        else
        {
            if( tree->left )
                interchange( tree->left, nodeID );
            if( tree->right )
                interchange( tree->right, nodeID );
            return tree;
        }
    }
    else return NULL;
}

int leaves( NodeT* tree )
{
    if( !tree )
        return 0;

    if( tree->left == NULL && tree->right == NULL )
        return 1;

    return leaves( tree->left ) + leaves( tree->right );
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
