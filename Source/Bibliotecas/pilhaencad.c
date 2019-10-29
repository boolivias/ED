#include "pilhaencad.h"
#include <stdlib.h>

void new_list(Lista *list);
int isEmpty(Lista list);
void Add(Lista *list, Node *n, T value);
void Remove(Lista *list, Node *n);
Node *IndexOf(Lista list, T value);
Node *getIndex(Lista list, int Index);
void Print(Lista list, int Index);

void new_list(Lista *list){
    *list = NULL;
}

int isEmpty(Lista list){
    return list==NULL;
}

void Add(Lista *lista, Node *n, T value){
    Node *new = ( Node* ) malloc( sizeof(Node) );
    new->Value = value;
    if ( isEmpty(*lista) ){
        new->Next = *lista;
        *lista = new;
    }
    else{
        new->Next = n->Next;
        n->Next = new;
    }
}

void Remove(Lista *list, Node *n){
    if( (*list)->Next != NULL ){
        Node *aux = n->Next;
        n->Next = aux->Next;
        free(aux);
        return;
    }
    Node *aux = *list;
    *list = (*list)->Next;
    free(aux);
}

Node *IndexOf(Lista list, T value){
    Node *n = list;
    while( n->Value != value )
        n = n->Next;
    return n;
}

Node *getIndex(Lista list, int Index){
    Node *n = list;
    while( 0 < Index-- )
        n = n->Next;
    return n;
}

void Print( Lista list, int Size ){
    Node *n = list;
    printf("Valores da lista\n\t");
    for(int i=0; i<Size; i++){
        printf("%d ", n->Value);
        n = n->Next;
    }
    printf("\n");
}