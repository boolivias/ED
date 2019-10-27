#include "fila.h"

void new_Fila(Fila *p, int Size);
int isEmpty(Fila *p);
int getFull(Fila *p);
int Add(Fila *p, T item, int op);
int Remove(Fila *p, T *item, int op);
void Clear(Fila *p);
void Print(Fila *p);
int getSize(Fila*p);
int Count(Fila *p);

void new_Fila(Fila *p, int Size){
    p->Start = 0;
    p->End = 0;
    p->Size = Size+1;
}

int isEmpty(Fila *p){
    if( p->Start == p->End )
        return 1;
    return 0;
}

int getFull(Fila *p){
    if( p->Start==0 && (p->End == getSize(p)-1) )
        return 1;
    if( p->End+1 == p->Start )
        return 1;

    return 0;
}

int Add(Fila *p, T item, int op){
    if( getFull(p) == 0 ){
        if( op == 0 ){
            p->Item[p->End++] = item;
            if( p->End == getSize(p) )
                p->End = 0;
        }
        else
            if( p->Start > 0 || p->Start > p->End )
                p->Item[--p->Start] = item;
            else{
                p->Start = getSize(p)-1;
                p->Item[p->Start] = item;
            }
        return 0;
    }
    return 1;
}

int Remove(Fila *p, T *item, int op){
    if( isEmpty(p) == 0 ){
        if( op == 0 )
            if( p->End > 0 )
                *item = p->Item[--p->End];
            else{
                p->End = getSize(p)-1;
                *item = p->Item[p->End];
            }
        else{
            *item = p->Item[p->Start++];
            p->Start = p->Start == getSize(p) ? 0 : p->Start;
        }
        return 0;
    }
    return 1;
}
void Clear(Fila *p){
    new_Fila(p, p->Size);
}
void Print(Fila *p){
    for(; !isEmpty(p); p->Start++){
        p->Start = p->Start < getSize(p) ? p->Start : 0;
        printf("%d ",p->Item[p->Start]);
    }
}
int getSize(Fila*p){
    return p->Size;
}
int Count(Fila *p){
    return p->Start < p->End ? p->End - p->Start : (getSize(p) - p->Start) + p->End+2;
}