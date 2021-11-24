#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

#define B 131

typedef struct cell {

    char key[100];
    struct cell* next;

} Node;

int f( char* );
char* readname( FILE* );
void insertc( Node*[B], char*, FILE* );
void afis( Node*[B], FILE* );
void find( Node*[B], char*, FILE* );
void delet( Node*[B], char*, FILE* );


#endif // FUNCTII_H_INCLUDED
