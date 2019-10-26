#include "pilha.h"

void new_pilha(Pilha *p, int Tam){
    *p->Item = { 's' };
    p->Index = 0;
    p->Tam = Tam;
}

void removeCadeia(Pilha *p, Index i){
    
}
int isEmpty(Pilha *p);
void Add(Pilha *p, T item);