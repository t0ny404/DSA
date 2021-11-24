#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "functii.h"

void preorder( BSTNode* p, int level, FILE* fout )
{
    int i;
    if ( p != NULL )
    {
        for (i = 0; i <= level; i++)
            fprintf( fout, " " );
        fprintf( fout, "%s\n", p->name );
        preorder( p->left, level + 1, fout );
        preorder( p->right, level + 1, fout );
    }
}

void inorder( BSTNode* p, int level, FILE* fout )
{
    int i;
    if ( p != NULL )
    {
        inorder( p->left, level + 1, fout );
        for ( i = 0; i <= level; i++ )
            fprintf( fout, " " );
        fprintf( fout, "%s\n", p->name );
        inorder( p->right, level + 1, fout );
    }
}

void postorder( BSTNode* p, int level, FILE* fout )
{
    int i;
    if ( p != NULL )
    {
        postorder( p->left, level + 1, fout );
        postorder( p->right, level + 1, fout );
        for ( i = 0; i <= level; i++ )
            fprintf( fout, " " );
        fprintf( fout, "%s\n", p->name );
    }
}

BSTNode* Insert( BSTNode* root, BSTNode* q, FILE* fout )
{
    if (root == NULL)
    {
        root = (BSTNode*)malloc( sizeof ( BSTNode ) );
        strcpy( root->name, q->name );
        root->price = q->price;
        root->amount = q->amount;
        root->dateOfManufacturing = q->dateOfManufacturing;
        root->dateOfExpiration = q->dateOfExpiration;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else
    {
        if ( strcmp( q->name, root->name ) < 0 )
            root->left = Insert( root->left, q, fout );
        else if ( strcmp( q->name, root->name ) > 0 )
            root->right = Insert( root->right, q, fout );
        else
            fprintf( fout, "Product of name=%s already exists\n", q->name );
    }
    return root;
}

BSTNode *deleteNode( BSTNode* root, char* key, FILE* fout )
{
    BSTNode* p;
    BSTNode* pParent;
    BSTNode* pRepl;
    BSTNode* pReplParent;
    int direction;

    if ( root == NULL )
        return NULL;

    p = root;
    pParent = NULL;

    while( p != NULL && strncmp( p->name, key, strlen( key ) ) != 0 )
    {
        if ( strcmp( key, p->name ) < 0 )
        {
            pParent = p;
            p = p->left;
            direction = LEFT;
        }
        else
        {
            pParent = p;
            p = p->right;
            direction = RIGHT;
        }
    }
    if ( p == NULL )
    {
        fprintf( fout, "No product of name=%s\n", key );
        return root;
    }

    if ( p->left == NULL )
        pRepl = p->right;

    else if ( p->right == NULL )
        pRepl = p->left;

    else
    {
        pReplParent = p;
        pRepl = p->right;
        while ( pRepl->left != NULL )
        {
            pReplParent = pRepl;
            pRepl = pRepl->left;
        }
        if ( pReplParent != p )
        {
            pReplParent->left = pRepl->right;
            pRepl->right = p->right;
        }
        pRepl->left = p->left;
    }

    free(p);
    fprintf( fout, "Deletion/Update of product %s completed\n", key );

    if ( pParent == NULL )
        return pRepl;
    else
    {
        if ( direction == LEFT )
            pParent->left = pRepl;
        else
            pParent->right = pRepl;
        return root;
    }
}

BSTNode* Find( BSTNode* root, char* key, FILE* fout )
{
    if ( root == NULL )
    {
        fprintf( fout, "empty tree/n" );
        return NULL;
    }
    while ( root != NULL )
    {
        if ( strncmp( root->name, key, strlen( key ) ) == 0 )
        {
            fprintf( fout, "Product found\n" );
            return root;
        }
        else if ( strncmp( key, root->name, strlen( key ) ) < 0 )
            root = root->left;
        else
            root = root->right;
    }
    fprintf(  fout, "Product not found\n" );
    return NULL;
}
