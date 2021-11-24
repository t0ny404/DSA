#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "functii.h"
#include "functii2.h"
#include <windows.h>

void delTree( BSTNode* root )
{
    if ( root != NULL )
    {
        delTree( root->left );
        delTree( root->right );
        free(root);
    }
}

void faraVirgula( FILE* fin )
{
    char ch[2];
    name[0] = '\0';
    fgets( ch, 2, fin );
    while( ch[0] != ',' && ch[0] != '\n' )
    {
        strcat( name, ch );
        fgets( ch, 2, fin );

    }
}

int tilda( FILE* fin )
{
    char ch[2];
    fgets( ch, 2, fin );
    while( ( ch[0] == ' ' || ch[0] == ',' ) && ch[0] != '\n' )
        fgets( ch, 2, fin );

    if( ch[0] == '~' )
        return 1;
    else
    {
        fseek( fin, -1, SEEK_CUR );
        return 0;
    }
}

BSTNode* update( BSTNode* root, BSTNode* p, FILE* fin, FILE* fout )
{
    if( p )
    {
        BSTNode* q = (BSTNode*)malloc( sizeof( BSTNode ) );
        q->left = q->right = NULL;

        if( tilda( fin ) == 0 )
        {
            faraVirgula( fin );
            strcpy( q->name, name );
        }
        else
        {
            fscanf( fin, "%*c" );
            strcpy( q->name, p->name );
        }
        if( tilda( fin ) == 0 )
            fscanf( fin, "%f", &(q->price) );
        else
            q->price = p->price;

        if( tilda( fin ) == 0 )
            fscanf( fin, "%*c%d", &(q->amount) );
        else
            q->amount = p->amount;

        if( tilda( fin ) == 0 )
            fscanf( fin, "%*c%ld", &(q->dateOfManufacturing) );
        else
            q->dateOfManufacturing = p->dateOfManufacturing;

        if( tilda( fin ) == 0 )
            fscanf( fin, "%*c%ld", &(q->dateOfExpiration) );
        else
            q->dateOfExpiration = p->dateOfExpiration;

        strcpy( name, p->name );
        root = deleteNode( root, name, fout );
        root = Insert( root, q, fout );

        delTree( q );
    }
    return root;
}

long time() {

    long today;
    SYSTEMTIME t;
    GetLocalTime(&t);

    today = t.wYear * 10000 + t.wMonth*100 + t.wDay;

    return today;
}

BSTNode* expired( BSTNode* ce, BSTNode* p, FILE* fout ) {

    if ( p != NULL )
    {
        expired( ce, p->left, fout );

        if( p->dateOfExpiration < time() )
        {
            BSTNode* q = (BSTNode*)malloc( sizeof( BSTNode ) );
            strcpy( q->name, p->name );
            q->price = p->price;
            q->amount = p->amount;
            q->dateOfManufacturing = p->dateOfManufacturing;
            q->dateOfExpiration = p->dateOfExpiration;
            q->left = q->right = NULL;

            ce = Insert( ce, q, fout );
        }
        expired( ce, p->right, fout );
        return ce;
    }
    return NULL;
}
