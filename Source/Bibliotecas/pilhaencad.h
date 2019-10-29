#ifndef PILHAENCAD_H
#define PILHAENCAD_H

typedef int T;

typedef struct node{
    T Value;
    struct node *Next;
} node;

typedef struct node Node;

typedef node *Lista;

void new_list(Lista *list);

int isEmpty(Lista list);

void Add(Lista *list, Node *n, T value);

void Remove(Lista *list, Node *n);

Node *IndexOf(Lista list, T value);

Node *getIndex(Lista list, int Index);

void Print(Lista list, int Index);

#endif