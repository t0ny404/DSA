#include <stdio.h>
#include <stdlib.h>


int recursiv (int* p, int aux)
{
    int len = 1;
    if(*p == 0)
        return 2;

    if( aux == 1)
        len += recursiv(p+1, aux);
    if( aux == 0)
        len += recursiv(p-1, aux);
    return len;
}
int main()
{
    int a[] = {0, 1, 2, 2, 3, 2, 2, 7, 8, 0};
    int* p = &a[3];
    printf("%d", recursiv(p, 0) + recursiv(p, 1) - 3);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int vecin;
int operatie(int n, int a[n], int new_val)
{
    int repeated = 0, first_time = 1, old;
    for( int i = 1; i < n; i++ )
    {
        if(a[i] == a[i-1])
        {
            repeated = 1;
            if( first_time == 1 )
                old = i - 1;
            first_time = 0;
            for( int j = i; j < n-1; j++ )
                a[j] = a[j+1];
            n--;
            i--;
        }
        else
            if(repeated == 1)
            break;
    }
    a[old] = new_val;
    vecin = (old == 0) ? 1 : old - 1;
    return n;
}
void aplOperatie( int n, int a[n] )
{
    if( sizeof(a) == 1)
    {
        printf("%d", a[0]);
        return;
    }
    int newn = operatie(n, a, a[vecin]);
    if( newn != n )
        {for( int i = 0; i < newn; i++ )
            printf("%d ", a[i]);
        printf("\n");}
    else return;
    aplOperatie(newn, a);
}
int main()
{
    int n;
    scanf("%d", &n );
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    //a
    int newn = operatie(n, a, a[0]);
    for(int i = 0; i < newn; i++)
        printf("%d ", a[i]);
    printf("\n");
    //b
    aplOperatie(newn, a);
    return 0;
}
