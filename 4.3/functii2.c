#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii2.h"

Node* createNode ( char c ) {

    Node* p = (Node*)malloc( sizeof ( Node ) );
    if( p )
    {
        p->operand = c;
        p->next = NULL;
    }
    return p;
}

    char c;
   scanf( "%c", &c );

    if( strchr( "+-*/", c ) == NULL )
    {
        p->operand = c;
        p->next = createNode();
        return p;
    }
    else
    {
        q->operand = c;
        q->next = createNode();
        return q;
    }
}

Tree* createBinTree (){

   Tree* Operator = (Tree*)malloc(sizeof( Tree ));
   if( Operator == NULL )
            printf( "Out of space in createBinTree" );

    List* p;




   {
       p = createNode ( c );
       createBinTree();
   }
   else
   {

   }
}

void inorder( Tree* p, int level)
{
    if( p != NULL )
    {
        inorder( p->left, level + 1 );
        for( int i = 0; i <= level; i++ )
            printf( " " );
        printf("%c\n", p->op );
        inorder( p->right, level + 1 );
    }
}

void postfix ( Tree* p ) {

    if( p )
    {
        printf( "%c", p->op );
        postfix( p->left );
        postfix( p->right );
    }
}
