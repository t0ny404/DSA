#ifndef FUNCTII2_H_INCLUDED
#define FUNCTII2_H_INCLUDED

#include "functii.h"

char name[500];

void delTree( BSTNode* root );
void faraVirgula( FILE* fin );
int tilda( FILE* fin );
BSTNode* update( BSTNode* root, BSTNode* p, FILE* fin, FILE* fout );
long time();
BSTNode* expired( BSTNode* ce, BSTNode* p, FILE* fout );

#endif // FUNCTII2_H_INCLUDED
