#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functii.h"

void preorder( BSTNode* p, int level, FILE* fout ) {
    int i;
    if ( p != NULL )
        {
            for (i = 0; i <= level; i++)
                fprintf( fout, " " );
            fprintf( fout, "%c\n", p->key );
            preorder( p->left, level + 1, fout );
            preorder( p->right, level + 1, fout );
        }
}

void inorder( BSTNode* p, int level, FILE* fout ) {
    int i;
    if ( p != NULL )
        {
            inorder( p->left, level + 1, fout );
            for ( i = 0; i <= level; i++ )
                fprintf( fout, " " );
            fprintf( fout, "%c\n", p->key );
            inorder( p->right, level + 1, fout );
        }
}

void postorder( BSTNode* p, int level, FILE* fout ) {
    int i;
    if ( p != NULL )
        {
            postorder( p->left, level + 1, fout );
            postorder( p->right, level + 1, fout );
            for ( i = 0; i <= level; i++ )
                fprintf( fout, " " );
            fprintf( fout, "%c\n", p->key );
        }
}

BSTNode* Insert( BSTNode* root, char key, FILE* fout ) {
    BSTNode *p;
    if (root == NULL)
        {
            p = (BSTNode*) malloc( sizeof( BSTNode ) );
            p->key = key;
            p->left = p->right = NULL;
            root = p;
            return root;
        } else
        {
            if ( key < root->key )
                root->left = Insert( root->left, key, fout );
            else if ( key > root->key )
                root->right = Insert( root->right, key, fout );
            else
                fprintf( fout, "Node of key=%c already exists\n", key );
        } return root;
}

BSTNode *deleteNode( BSTNode* root, char key, FILE* fout ) {
    BSTNode* p;
    BSTNode* pParent;
    BSTNode* pRepl;
    BSTNode* pReplParent;
    int direction;

    if ( root == NULL )
        return NULL;

    p = root;
    pParent = NULL;

    while( p != NULL && p->key != key )
        {
            if ( key < p->key )
            {
                pParent = p;
                p = p->left;
                direction = LEFT;
            } else {
                pParent = p;
                p = p->right;
                direction = RIGHT;
                    }
        }
        if ( p == NULL )
            {
                fprintf( fout, "\nNo node of key value=%c\n", key );
                return root;
            }

        if ( p->left == NULL )
            pRepl = p->right;

        else if ( p->right == NULL )
            pRepl = p->left;

            else {
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
        fprintf( fout, "\nDeletion of node %c completed\n", key );

        if ( pParent == NULL )
                return pRepl;
        else {
                if ( direction == LEFT )
                pParent->left = pRepl;
                else pParent->right = pRepl;
                return root;
            }
}

void Find( BSTNode* root, char key, FILE* fout ) {
    BSTNode* p;
    if ( root == NULL )
       {
        fprintf( fout, "empty tree/n" );
        return;
       }
    p = root;
    while ( p != NULL )
        {
            if ( p -> key == key )
                  {
                      fprintf( fout, "Node found\n" );
                      return;
                  }
            else if ( key < p->key )
                    p = p->left;
                else p = p->right;
        }
    fprintf( fout, "Node not found\n" );
    return;
}

BSTNode* findMin( BSTNode* node ) {

    if( node == NULL )
        return NULL;

    if( node->left )
        return findMin( node->left );
    else return node;
}

BSTNode* findMax( BSTNode* node ) {

    if( node == NULL )
        return NULL;

    if( node->right )
        return findMax( node->right );
    else return node;
}
