#ifndef PILHA_H
#define PILHA_H

#define MAX 100000

typedef char T;
typedef int Index;

typedef struct pilha
{
    T Item[MAX];
    Index Index;
    int Tam;
} Pilha;

void new_pilha(Pilha *p, int Tam);

void removeCadeia(Pilha *p, Index i);

int isEmpty(Pilha *p);

void Add(Pilha *p, T item);

#endif