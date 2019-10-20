#ifndef FILA_H
#define FILA_H

#define MAX 550000

typedef int T;

typedef int Index;

//criação da classe da fila
typedef struct fila{
    T Item[MAX];
    Index Start;
    Index End;
    int Size;
} Fila;

//Função que instancia a fila
void new_Fila(Fila *p, int Size);

//Função que verifica se a fila está vazia
int isEmpty(Fila *p);

//Função que verifica se a fila está cheia
int getFull(Fila *p);

//Função que insere o item na fila na posição especificada
int Add(Fila *p, T item, int op);

//Função que remove o item da fila na posição especificada, e coloca no ponteiro item
int Remove(Fila *p, T *item, int op);

//Função que esvazia a fila
void Clear(Fila *p);

//Função que printa a fila
void Print(Fila *p);

//Função que retorna o tamanho máximo da fila
int getSize(Fila*p);

//Função que retorna o número de elementos na fila
int Count(Fila *p);

#endif // FILA_H
