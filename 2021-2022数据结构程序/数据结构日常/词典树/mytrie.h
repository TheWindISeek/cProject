#ifndef MYTRIE_H_INCLUDED
#define MYTRIE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#define MAXKEYLEN 16

typedef struct
{
    char ch[MAXKEYLEN];
    int num;
}KeysType;

typedef enum{LEAF,BRANCH}NodeKind;
typedef char Record;

typedef struct DLTNode
{
    char symbol;
    struct DLTNode *next;
    NodeKind kind;
    union
    {
        Record *infoptr;
        struct DLTNode *first;
    }Ptr;
}DLTNode,*DLTree;

int CreateDLTree(DLTree &DT);
Record *SearchDLTree(DLTree DT,KeysType key);
int InsertDLTree(DLTree &DT,KeysType key);
void PrintfKeys(DLTree DT);
void DeleteDLTree(DLTree &DT,KeysType &key,int locate);

void gotoxy(int x,int y);

#endif // MYTRIE_H_INCLUDED
