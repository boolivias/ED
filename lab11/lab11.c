#include <stdio.h>
#include <stdlib.h>
typedef int T;
typedef int Index;

typedef struct fila
{
    T *item;
    Index Start;
    Index End;
    int Size;
}Fila;

void new_Fila(Fila *f, int Size);
void Add(Fila *f, T item);
int Remove(Fila *f, T *item);
void Inverte(Fila *f);
int isEmpty(Fila *f);
int isFull(Fila *f);
int getSize(Fila *f);
void Resize(Fila *f);
void Print(Fila *f);

int main(){
    int n;
    T item;
    Fila f;
    scanf("%d",&n);
    new_Fila(&f, n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&item);
        Add(&f, item);
    }
    Inverte(&f);
    Print(&f);
}

void new_Fila(Fila *f, int Size){
    f->Start = 0;
    f->End = 0;
    f->Size = Size;
    f->item = (T *)malloc( Size*sizeof(T) );
}

void Add(Fila *f, T item){
    if( isFull(f) ){
        Resize(f);
    }
    f->item[f->End++] = item;
}

int Remove(Fila *f, T *item){
    if( !isEmpty(f) ){
        *item = f->item[f->Start++];
        return 0;
    }
    return 1;
}

void Inverte(Fila *f){
    T item;
    int e = Remove(f, &item);
    if( !e ){
        Inverte(f);
        Add(f, item);
    }
}

int isEmpty(Fila *f){
    if( f->Start == f->End )
        return 1;
    return 0;
}

int isFull(Fila *f){
    if( f->End == f->Size ){
        return 1;
    }
    return 0;
}

int getSize(Fila *f){
    return f->Size;
}

void Resize(Fila *f){
    f->Size *= 2;
    f->item = (T *) realloc( f->item, getSize(f)*sizeof(T) );
}

void Print(Fila *f){
    for (int i = f->Start; i < f->Size; i++)
    {
        printf("%d",f->item[i]);
        if( i<f->Size-1 )
            printf(" ");
    }
    printf("\n");
}