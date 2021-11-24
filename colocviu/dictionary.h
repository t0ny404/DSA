#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED

typedef enum{ FALSE, TRUE } BoolT;   //boolean type

typedef struct node {               //structure to hold a node representing a word

    char word[26];
    struct node* next;
    struct node* prev;

} NodeT;

typedef struct {                   //list to hold the words in the dictionary and the query

    int count;                      //nr of words in dictionary/query
    NodeT* first;                   //first and last word
    NodeT* last;

} ListT;

ListT* CreateEmpty();
void insertt( ListT* listptr, char w[26] );
void misspelling( FILE* out, ListT* dictionaryL, int nD, ListT* queryL, int nQ );

#endif // DICTIONARY_H_INCLUDED
