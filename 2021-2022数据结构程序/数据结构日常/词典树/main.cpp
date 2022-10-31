#include <iostream>
#include <windows.h>
#include "mytrie.h"
using namespace std;

int CreateDLTree(DLTree &DT)
{
    DT = new DLTNode;
    DT->kind = BRANCH;
    DT->symbol = '\0';
    DT->next = NULL;
    DT->Ptr.first = NULL;
    int ch,n;
    char str[800];
    KeysType tmp;
    FILE *fp1,*fp2;
    fp1 = fopen("初始输入.txt","r+");
    if(fp1 == NULL)
    {
        cout << "初始输入.txt文件打开失败！";
        exit(-1);
    }

    while(ch != EOF)
    {
        putchar(ch);
        ch = fgetc(fp1);
    }
    fclose(fp1);
    fp2 = fopen("单词输入.txt","r+");
    if(fp2 == NULL)
    {
        cout << "单词输入.txt文件打开失败！";
        exit(-1);
    }
    fgets(str, sizeof(str), fp2);
    puts(str);
    fclose(fp2);
    cout << endl << "请输入您想要插入的字符串个数：";
    cin >> n;
    cout <<"请输入您想要插入的单词："<< endl;
    while(n--)
    {
        cin >> tmp.ch;
        tmp.num = strlen(tmp.ch);
        InsertDLTree(DT,tmp);
    }
    return 1;
}

Record *SearchDLTree(DLTree DT,KeysType key)
{
    DLTree p = DT->Ptr.first;
    int i = 0;
    while(p && i < key.num)
    {
        while( p && p->symbol < key.ch[i])
            p = p->next;
        if(p && p->symbol == key.ch[i])
        {
            p = p->Ptr.first;
            i++;
        }
        else
            p = NULL;
    }
    if (p && p->kind == LEAF)
        return p->Ptr.infoptr;
    return NULL;
}

int InsertDLTree(DLTree &DT,KeysType key)
{
    DLTree p = DT;
    DLTree q = DT->Ptr.first;
    DLTNode *tmp = NULL;
    int i = 0;
    while(i < key.num)
    {
        while(q && q->symbol < key.ch[i])
        {
            p = q;
            q = q->next;
        }
        if(q && q->symbol == key.ch[i])
        {
            p = q;
            q = q->Ptr.first;
            i++;
        }
        else
        {
            tmp = new DLTNode;
            tmp->kind = BRANCH;
            tmp->symbol = key.ch[i];
            tmp->Ptr.first = NULL;
            if(p->Ptr.first == q)
            {
                p->Ptr.first = tmp;
                tmp->next = q;
            }
            else
            {
                p->next = tmp;
                tmp->next = q;
            }
            p = tmp;
            i++;
            while(i < key.num)
            {
                tmp = (DLTNode *)malloc(sizeof(DLTNode));
                tmp->kind = BRANCH;
                tmp->symbol = key.ch[i];
                tmp->Ptr.first = NULL;
                tmp->next = NULL;
                p->Ptr.first = tmp;
                p = p->Ptr.first;
                i++;
            }
            tmp = (DLTNode *)malloc(sizeof(DLTNode));
            tmp->kind = LEAF;
            tmp->symbol = '$';

            char *t_c = (char *)malloc((key.num + 1)*sizeof(char));
            tmp->Ptr.infoptr = strcpy(t_c,key.ch);

            tmp->next = NULL;
            p->Ptr.first = tmp;
            p = p->Ptr.first;
            i++;
        }
    }
    return 1;
}

void DeleteDLTree(DLTree &DT,KeysType &key,int locate)
{

}

void PrintfKeys(DLTree DLT)
{
    if(DLT)
    {
        if(DLT->symbol == '$')
            cout << DLT->Ptr.infoptr << endl;
        else
            PrintfKeys(DLT->Ptr.first);
        PrintfKeys(DLT->next);
    }
}

void gotoxy(int x,int y)
{
    COORD pos;
    pos.X = y;
    pos.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int main()
{
    cout << "欢迎您来到Trie树-英语词典的维护和识别系统！" << endl ;
    cout << "请按系统指示进行操作！" << endl ;
    cout << "感谢您的合作！" << endl ;
    DLTree DT = NULL;
    CreateDLTree(DT);
    cout <<"输出字符串结果为："<< endl ;
    PrintfKeys(DT);
    char *k = NULL;
    KeysType tmp;
    int selection;
    while(1)
    {
        cout << endl << "请您输入接下来想要进行的操作：" << endl ;
        printf("1：查找  2：删除  0：退出系统        ");
        cin >> selection;
        if(!selection)
            break;
        switch(selection)
      {
        case 1:
            cout << endl <<"请您输入需要查找的单词：";
            cin >> tmp.ch;
            tmp.num = strlen(tmp.ch);
            k = SearchDLTree(DT,tmp);
            if(k)
                printf("\n找到了您查找的单词:%s\n",k);
            else
                printf("\n您查找的单词不存在！\n");
            break;

        case 2:
            cout << endl << "请您输入想要删除的单词：";
            cin >> tmp.ch;
            tmp.num = strlen(tmp.ch);
            k = SearchDLTree(DT,tmp);
            if(!k)
                cout << endl<< "您想要删除的单词不存在！" << endl;
            else
            {

            }
            break;

        case 'a':
            cout << endl << "操作有误，请您重新输入！" << endl;
            break;

        default:
            cout << endl << "操作有误，请您重新输入！" << endl;
            break;
      }
    }
    cout << endl <<"感谢您的使用！" << endl ;
    return 0;
}
