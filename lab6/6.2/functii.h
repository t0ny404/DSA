#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

#define B 131

typedef struct {

    char key[100];

} Node;

int f1( char* );
int f( char*, int );
char* readname( FILE* );
void insertq( Node*[B], char*, FILE*, int );
void afis( Node*[B], FILE* );
int find( Node*[B], char*, int );
void delet( Node*[B], char*, FILE* );

#endif // FUNCTII_H_INCLUDED
