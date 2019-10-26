#include <stdio.h>
#include "fila.h"

int main(){
    int n = 0, m = 0, error = 0;
    char op = 0, op2 = 0;
    T item;
    Fila f;
    scanf("%d",&n);
    scanf("%d",&m);
    new_Fila(&f, m);

    for( int i=0; i<n; i++ ){
        op = 0; op2 = 0;
        while ( op!='r' && op!='i')
            op = getchar();
        while ( op2!='I' && op2!='F' )
            op2 = getchar();

        //printf("op: %c, op2: %c\n", op, op2);
        if(op == 'i'){
            scanf("%d",&item);
            if(op2 == 'I')
                error = Add(&f, item, 1);
            else
                error = Add(&f, item, 0);


            if( error )
                printf("cheia\n");
        }else{
            if(op2 == 'I')
                error = Remove(&f, &item, 1);
            else
                error = Remove(&f, &item, 0);


            if( error )
                printf("vazia\n");
            else
                printf("%d\n",item);
        }
    }
    return 0;
}