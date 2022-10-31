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
    fp1 = fopen("��ʼ����.txt","r+");
    if(fp1 == NULL)
    {
        cout << "��ʼ����.txt�ļ���ʧ�ܣ�";
        exit(-1);
    }

    while(ch != EOF)
    {
        putchar(ch);
        ch = fgetc(fp1);
    }
    fclose(fp1);
    fp2 = fopen("��������.txt","r+");
    if(fp2 == NULL)
    {
        cout << "��������.txt�ļ���ʧ�ܣ�";
        exit(-1);
    }
    fgets(str, sizeof(str), fp2);
    puts(str);
    fclose(fp2);
    cout << endl << "����������Ҫ������ַ���������";
    cin >> n;
    cout <<"����������Ҫ����ĵ��ʣ�"<< endl;
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
    cout << "��ӭ������Trie��-Ӣ��ʵ��ά����ʶ��ϵͳ��" << endl ;
    cout << "�밴ϵͳָʾ���в�����" << endl ;
    cout << "��л���ĺ�����" << endl ;
    DLTree DT = NULL;
    CreateDLTree(DT);
    cout <<"����ַ������Ϊ��"<< endl ;
    PrintfKeys(DT);
    char *k = NULL;
    KeysType tmp;
    int selection;
    while(1)
    {
        cout << endl << "���������������Ҫ���еĲ�����" << endl ;
        printf("1������  2��ɾ��  0���˳�ϵͳ        ");
        cin >> selection;
        if(!selection)
            break;
        switch(selection)
      {
        case 1:
            cout << endl <<"����������Ҫ���ҵĵ��ʣ�";
            cin >> tmp.ch;
            tmp.num = strlen(tmp.ch);
            k = SearchDLTree(DT,tmp);
            if(k)
                printf("\n�ҵ��������ҵĵ���:%s\n",k);
            else
                printf("\n�����ҵĵ��ʲ����ڣ�\n");
            break;

        case 2:
            cout << endl << "����������Ҫɾ���ĵ��ʣ�";
            cin >> tmp.ch;
            tmp.num = strlen(tmp.ch);
            k = SearchDLTree(DT,tmp);
            if(!k)
                cout << endl<< "����Ҫɾ���ĵ��ʲ����ڣ�" << endl;
            else
            {

            }
            break;

        case 'a':
            cout << endl << "�������������������룡" << endl;
            break;

        default:
            cout << endl << "�������������������룡" << endl;
            break;
      }
    }
    cout << endl <<"��л����ʹ�ã�" << endl ;
    return 0;
}
