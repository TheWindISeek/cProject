#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stack>
//const define
//��������󳤶�
//������󳤶�
//������󳤶�
//���Ľ�����
//������ֵĳ���
//������󳤶�
//�����
//�޷�����
//�˳�
//����
//����
#define MAX_LENGTH 5
#define MAX_NAME 50
#define MAX_ABSTRACT 50
#define MAX_NODE 100
#define MAX_NODE_LENGTH 7
#define MAX_PASSWORD_LENGTH 5
#define INFINITY 0x7fffffff
#define NotReach -1
#define EXIT 0
#define ERROR -1
#define HELP -2
//type define
using namespace std;
typedef int Weight;//Ȩֵ
typedef int Position;//λ��
typedef struct graph* Graph;//ͼ�ṹָ��
typedef struct//ÿ������Ľṹ��
{
    int mark;//����
    char name[MAX_NODE];//����
    char abstract[MAX_NODE];//���
} Scenery;
struct graph//���ͼ
{
    int vertex_num;//������
    int edge_num;//�߸���
    Weight matrix[MAX_NODE][MAX_NODE];//�ڽӾ���洢����Ȩͼ
    Scenery vertex[MAX_NODE];//ÿ���������Ϣ
};
//function declare

//ͼ��ز���
Graph creatGraph(int, int);//����һ��ͼ
inline void print(Graph);//��ӡ���н�����Ϣ �������
void print(Graph, bool);//��ӡͼ bool���ڿ����Ƿ�������
inline void print(Graph, Position, bool);//��ӡ��Ӧ������Ϣ bool���ڿ����Ƿ��ӡ���
inline void print(Graph, Position, Position);//��ӡ�ӵ�һ���㵽�ڶ��������Ϣ

//�����������
int getOp();//������������ ���ص������Ӧ�Ĳ�������֮ǰ��HELP ����Cd ����cd������ ����ݴ�
char* transToLower(char*);//�������ַ�����ΪСд ���������ַ���
void listOp();//�г�������������
bool isNum(char*);//�ж�һ���ַ����Ƿ�������
int transToInt(char*);//��һ���ַ���ת��������bool
bool visitorSystem(Graph);//�ο�ϵͳ�ĺ��� ���ص����Ƿ��˳�����ı�־����
int readNode(int);//int�������ƶ�ȡ���ݵ������ֵ ����һ�������������ȡ������
char* getLength(char*,int);//����������ȡָ�������ַ����������ַ�����

//����ģ�麯��
bool managerSystem(Graph, char*);//����Աϵͳ ���ص����Ƿ��˳�����ı�־
bool checkInformation(Graph);//����������Ϣ��ģ��
void searchShort(Graph);//�������·ģ��
void currentShortPath(Graph);//��ǰ��㵽����������·
void searchName(Graph);//�������� ֧��ģ����ѯ
void searchMark(Graph);//������� ��֧��ģ����ѯ
void search(Graph, bool(*)(char*, Scenery&));//����ģ�� �������ŵĲ�ͬ�����ڱȽϵĲ�ͬ
bool nameCmp(char*, Scenery&);//���ڱȽ����Ƶĺ���
bool markCmp(char*, Scenery&);//���ڱȽϱ�ŵĺ���
void modifyInformation(Graph);//�޸ľ�����Ϣģ��
void addScenary(Graph);//��Ӿ��� ֱ���ڽ��֮�����
void deleteScenary(Graph);//��Ҫɾ�������������������������һ��������ݽ��н���Ȼ��ɾ�����һ���������� ��Ϊ�ҵĽ�㶼�ǰ��������� ���Ǳ�Ų�û��ʲôʵ������ ���Խ�����ŵ�λ������ν
void addRoad(Graph);//��ӵ�·ģ��
void deleteRoad(Graph);//ɾ����·ģ��
bool checkPassword(char*);//�ж�����ַ����Ƿ�������
void shortPath(Graph, Position, int);//��ǰ�����Ƿ���ʾ·�� int�������Ƴ���
void shortPath(Graph, Position, Position, bool);//��ӡ������������֮������·�� bool���ڿ����Ƿ��������·��

//���ĺ���
bool dijisktra(Graph, Position, int[], int[]);//�����·���㷨 ������� ͼ ��� ��¼·�������� ��¼��������� ���سɹ���׼
//ÿ��ϵͳ����ʾ��Ϣ
void printMainInformation();
void printVisitorInformation();
void printManagerSystem();
void printCheckInformation();
int main()
{
    Graph g = creatGraph(31, 56);//���ո����������ɵ�ͼ
    int op;
    char  password[MAX_PASSWORD_LENGTH] = "1234";//��ʼ����
    bool isControl = true;//���ڿ���ѭ���ı���
    system("title �ӱ���ѧУ԰����ϵͳ-��ҳ��");
        printf("����������ӭ�����ӱ���ѧУ԰����ϵͳ\n");
        printf("��ѡ���㽫Ҫ���еĲ���\n");
        printf("1.�ο�ϵͳ\n");
        printf("2.����Աϵͳ\n");
        printf("3.�˳�����ϵͳ\n");
        printf("�����ṩ����,������help\n�����ε��\n����ʾ��!!!\ncd �س� 1 �س�\nhelp\nexit\n�벻Ҫ������ո� ���򽫻�ֱ���˳�ϵͳ\n");
    do
    {

        //printf("�����ṩ����,������help\n�����ε��\n����ʾ��!!!\ncd �س� 1 �س�\nhelp\nexit\n�벻Ҫ������ո� ���򽫻�ֱ���˳�ϵͳ\n");
        isControl = true;
        op = getOp();//����������ò�����
        switch (op)
        {
        case ERROR:
            printf("�����������������\n");
            system("pause");
            break;
        case HELP:
            listOp();
            printf("\n");
            break;
        case EXIT:
            exit(0);
            break;
        case 1://�ο�ģ��
            isControl = visitorSystem(g);
            system("cls");
            printMainInformation();
            break;
        case 2://����Աģ��
            isControl = managerSystem(g, password);
            system("cls");
            printMainInformation();
            break;
        case 3://ֱ���˳�
            exit(0);
            break;
        default:
            printf("�������������\n");
            system("pause");
        }
    } while (isControl);
    return 0;
}
void printMainInformation(){
        system("title �ӱ���ѧУ԰����ϵͳ-��ҳ��");
        printf("����������ӭ�����ӱ���ѧУ԰����ϵͳ\n");
        printf("��ѡ���㽫Ҫ���еĲ���\n");
        printf("1.�ο�ϵͳ\n");
        printf("2.����Աϵͳ\n");
        printf("3.�˳�����ϵͳ\n");
        printf("�����ṩ����,������help\n�����ε��\n����ʾ��!!!\ncd �س� 1 �س�\nhelp\nexit\n�벻Ҫ������ո� ���򽫻�ֱ���˳�ϵͳ\n");
}
void printVisitorInformation(){
        printf("����������ӭ�����ο�ϵͳ\n");
        printf("1.��ѯ������Ϣ\n");
        printf("2.����������֮�����·��\n");
        printf("3.��ǰ���㵽������������·��\n");
        printf("4.������һ��ϵͳ\n");
        printf("�����ṩ����,������help\n�����ε��\n����ʾ��!!!\ncd �س� 1 �س�\nhelp\nexit\n�벻Ҫ������ո� ���򽫻�ֱ���˳�ϵͳ\n");
}
void printManagerSystem(){
            printf("����������ӭ��������Աϵͳ\n");
            printf("1.��ѯ������Ϣ\n");
            printf("2.����������֮�����·��\n");
            printf("3.��ǰ���㵽������������·��\n");
            printf("4.�޸ľ�����Ϣ\n");
            printf("5.���Ӿ���\n");
            printf("6.ɾ������\n");
            printf("7.���ӵ�·\n");
            printf("8.ɾ����·\n");
            printf("9.������һ��ϵͳ\n");
            printf("�����ṩ����,������help\n�����ε��\n����ʾ��!!!\ncd �س� 1 �س�\nhelp\nexit\n�벻Ҫ������ո� ���򽫻�ֱ���˳�ϵͳ\n");
}
void printCheckInformation(){
        printf("1.����ѧУ�ľ�����Ϣ\n");
        printf("2.ѡ�����ƽ��в�ѯ\n");
        printf("3.ѡ���Ž��в�ѯ\n");
        printf("4.������һ��ϵͳ\n");
        printf("�����ṩ����,������help\n�����ε��\n����ʾ��!!!\ncd �س� 1 �س�\nhelp\nexit\n�벻Ҫ������ո� ���򽫻�ֱ���˳�ϵͳ\n");
}
int transToInt(char* s)//������ַ���ת��Ϊint����
{
    int n = 0;
    char* p = s;
    while (*p != '\0')
    {
        n = n * 10 + (*p - '0');
        p++;
    }
    return n;
}
bool isNum(char* s)//�ж�����ַ����Ƿ�������
{
    char* p = s;
    while (*p != '\0')
    {
        if (*p < '0' || *p >'9')
            return false;
        p++;
    }
    if (p == s)
        return false;
    return true;
}
char* transToLower(char* s)//���ַ���ת��ΪСд
{
    char* p = s;
    while (*p != '\0')
    {
        if (*p >= 'A' && *p <= 'Z')
            *p += 32;
        p++;
    }
    return s;
}
char* getLength(char* s, int length)//���������ж�ȡ��󳤶�Ϊlength�����ݵ�s��
{
    int i = 0;
    char c;
    while ((c = getchar()) != '\0')
    {
        if (c == '\n' || c == '\0' || c == '\t')
        {
            s[i] = '\0';
            break;
        }
        s[i++] = c;
        if (i == length)
        {
            s[i] = '\0';
            break;
        }
    }
    return s;
}
void listOp()//�������
{
    printf("�������뽫Ҫ���еĲ���\n");
    printf("�������ĳ�����������cd �����뽫Ҫ���еĲ�����Ӧ�ı�� ��cd �س� 1 �س�\n");
    printf("�����ȡ���� ������help\n");
    printf("�����˳�ϵͳ ������exit\n");
    printf("���Ͻ��ڴ��ڲ�����ŵ������ʹ�ã����������Ҫ�����뼴��\n");
    system("pause");
}
int emptyStream()//������뻺����
{
    char c;
    while ((c = getchar()) != '\n');
    return 1;
}
int getOp()//��ò�����
{
    char s[MAX_LENGTH];//ѡ����ֲ���
    char op[MAX_LENGTH];//���ֶ�ȡ
    getLength(s, MAX_LENGTH);
    //cin.getline(s,MAX_LENGTH,' ');
    //emptyStream();
    transToLower(s);//ת��ΪСд ����ݴ�
    //printf("���ǵõ��Ľ��%s\n",s);
    if (strcmp(s, "cd") == 0)//cd����
    {
        printf("��������Ҫ���еĲ���\n");
        getLength(op, MAX_LENGTH);//��ȡ����
        //cin.getline(op,MAX_LENGTH,'\n');
        //printf("���ǵõ��ĵڶ����ַ���%s",op);
        //emptyStream();
        if (isNum(op))//��������� ��ֱ�ӷ��ض�Ӧ������ ��������������
            return transToInt(op);
        else
            return ERROR;
    }
    else if (strcmp(s, "help") == 0)
    {
        printf("���ǰ���");
        return HELP;
    }
    else if (strcmp(s, "exit") == 0)
    {
        return EXIT;
    }
    else//�ʼ�Ĳ����ʹ�����
    {
        emptyStream();//
        return ERROR;
    }
}
Graph creatGraph(int vertex_num, int edge_num)//���ո����Ľ���� ������������
{
    Graph g = (Graph)malloc(sizeof(struct graph));
    g->vertex_num = vertex_num;
    g->edge_num = edge_num;
    int i, j;
    //�ȳ�ʼ��Ϊ����
    for (i = 0; i < MAX_NODE; i++)
        for (j = 0; j < MAX_NODE; j++)
            g->matrix[i][j] = INFINITY;
    /*����Ϊ�����ĳ�ʼ����*/
    g->matrix[0][1] = g->matrix[1][0] = 82;
    g->matrix[1][2] = g->matrix[2][1] = 111;
    g->matrix[1][4] = g->matrix[4][1] = 92;
    g->matrix[2][3] = g->matrix[3][2] = 80;
    g->matrix[2][7] = g->matrix[7][2] = 91;
    g->matrix[2][6] = g->matrix[6][2] = 84;
    g->matrix[3][4] = g->matrix[4][3] = 105;
    g->matrix[4][7] = g->matrix[7][4] = 178;
    g->matrix[4][9] = g->matrix[9][4] = 93;
    g->matrix[5][6] = g->matrix[6][5] = 44;
    g->matrix[5][11] = g->matrix[11][5] = 49;
    g->matrix[5][10] = g->matrix[10][5] = 92;
    g->matrix[6][11] = g->matrix[11][6] = 25;
    g->matrix[6][12] = g->matrix[12][6] = 102;
    g->matrix[6][7] = g->matrix[7][6] = 114;
    g->matrix[7][8] = g->matrix[8][7] = 57;
    g->matrix[7][12] = g->matrix[12][7] = 108;
    g->matrix[8][10] = g->matrix[10][8] = 179;
    g->matrix[8][13] = g->matrix[13][8] = 53;
    g->matrix[8][14] = g->matrix[14][8] = 59;
    g->matrix[9][14] = g->matrix[14][9] = 202;
    g->matrix[9][18] = g->matrix[18][9] = 37;
    g->matrix[10][11] = g->matrix[11][10] = 20;
    g->matrix[10][15] = g->matrix[15][10] = 20;
    g->matrix[11][16] = g->matrix[16][11] = 5;
    g->matrix[11][12] = g->matrix[12][11] = 15;
    g->matrix[12][13] = g->matrix[13][12] = 115;
    g->matrix[13][14] = g->matrix[14][13] = 56;
    g->matrix[14][19] = g->matrix[19][14] = 39;
    g->matrix[15][16] = g->matrix[16][15] = 10;
    g->matrix[15][17] = g->matrix[17][15] = 134;
    g->matrix[18][19] = g->matrix[19][18] = 210;
    g->matrix[18][20] = g->matrix[20][18] = 134;
    g->matrix[18][21] = g->matrix[21][18] = 60;
    g->matrix[19][20] = g->matrix[20][19] = 77;
    g->matrix[19][22] = g->matrix[22][19] = 96;
    g->matrix[19][23] = g->matrix[23][19] = 114;
    g->matrix[20][24] = g->matrix[24][20] = 78;
    g->matrix[21][26] = g->matrix[26][21] = 93;
    g->matrix[21][25] = g->matrix[25][21] = 44;
    g->matrix[22][23] = g->matrix[23][22] = 91;
    g->matrix[23][24] = g->matrix[24][23] = 190;
    g->matrix[23][27] = g->matrix[27][23] = 20;
    g->matrix[24][25] = g->matrix[25][24] = 87;
    g->matrix[24][27] = g->matrix[27][24] = 20;
    g->matrix[24][28] = g->matrix[25][24] = 167;
    g->matrix[24][29] = g->matrix[29][24] = 73;
    g->matrix[25][26] = g->matrix[26][25] = 75;
    g->matrix[25][29] = g->matrix[26][25] = 42;
    g->matrix[26][30] = g->matrix[30][26] = 150;
    g->matrix[26][29] = g->matrix[29][26] = 110;
    g->matrix[27][28] = g->matrix[28][27] = 139;
    g->matrix[28][29] = g->matrix[29][28] = 169;
    g->matrix[29][30] = g->matrix[30][29] = 144;
    char dresnam[MAX_NODE][MAX_NAME] = { "УҽԺ","����Ժ","����ѧԺ","������","�ݷ�¥","����÷԰6��","��Ժ����","��ѧѧԺ","����ѧԺ","��2�ſ�",
                                        "����÷԰3��4��5��","��������","����ѧԺ","��ѧ¥","��1�ſ�","����÷԰2��","�ٳ�","ѧ������÷԰1��",
                                        "��1�ſ�","��2�ſ�","ͼ���","��Է¥","�๦�ܹ�","��¥","�ھŽ�ѧ¥","�ڰ˽�ѧ¥","��Ժ����","ع��԰","���ʽ���ѧԺ","�ۺϽ�ѧ¥","���߽�ѧ¥"
    };
    char dresinfo[MAX_NODE][MAX_ABSTRACT] = { "������ȥ����","������ѧѧԺ","�����빤��ѧԺ","����ѧ����","��ϰ��",
                                              "����","���ߵĲ���","��ѧ��ѧѧԺ","�����ѧѧԺ","ǰ������ĵ�2���ſ�","����",
                                              "����ĵط�","������ϢѧԺ","��ϰ��","ǰ������ĵ�1���ſ�","����","�ܲ���","����",
                                              "ǰ�����ߵĵ�1���ſ�","ǰ�����ߵĵ�2���ſ�", "����ĵط�","��ϰ��","������",
                                              "��ϰ��","��ϰ��","��ϰ��","����Է���","����","��֪��",
                                              "��ϰ��","��ϰ��"
    };
    for (i = 0; i < MAX_NODE; i++)
    {
        strcpy(g->vertex[i].abstract, dresinfo[i]);
        strcpy(g->vertex[i].name, dresnam[i]);
        g->vertex[i].mark = i;
    }

    return g;
}
inline void print(Graph g, Position v, bool check)//��ӡ����ĳ���������� �������ں��������С���� ���������
{
    if (check)
        printf("%2d:%5s\t", g->vertex[v].mark, g->vertex[v].name);
    else
        printf("%2d:%5s %6s\t", g->vertex[v].mark, g->vertex[v].name, g->vertex[v].abstract);
}
void print(Graph g, bool check)//������н�����Ϣ check�����Ƿ���Ҫ������
{
    int j = 3;
    Position i;
    printf("\t����Ϊ����ѧУ���еľ���\t\n���ǵĸ�ʽ�����·�ʽ���� �����ţ���������");
    for (i = 0; i != g->vertex_num; i++)
    {
        if (++j == 4)
        {
            printf("\n��%d��|\t", (i / 4) + 1);
            j = 0;
        }
        print(g, i, check);
    }
    printf("\n\t�ܹ���%d������", g->vertex_num);
}
inline void print(Graph g)//��ӡ���н�����Ϣ
{
    print(g, true);
}
bool dijisktra(Graph g, Position v, int path[], int distant[])//���ĵ�dijistra�㷨
{
    int visit[MAX_NODE] = { 0 };//���еĽ�㶼û�б�����
    int i, j;//����ѭ���ı���
    Position minV;//��¼��С����±�
    int minDistant = INFINITY;//��̾�����Ϊ�����
    for (i = 0; i < g->vertex_num; i++)
    {
        distant[i] = g->matrix[v][i];//��ʼ������
        if (g->matrix[v][i] != INFINITY)//�ܵ� �Ͱ��ϸ�������ΪԴ��
            path[i] = v;
        else//������ܵ��� �ͱ��Ϊ���ܵ���
            path[i] = NotReach;
    }
    //��¼Դ��
    distant[v] = 0;
    visit[v] = 1;
    while (1)
    {
        minV = NotReach;//�޷�����
        minDistant = INFINITY;//����Զ
        for (j = 0; j < g->vertex_num; j++)//������͵Ľ��
            if (!visit[j] && distant[j] < minDistant)
            {
                minV = j;
                minDistant = distant[j];
            }
        if (minDistant == INFINITY)//�Ҳ����˾��˳�
            break;
        visit[minV] = 1;//���������
        for (i = 0; i < g->vertex_num; i++)//���½��
        {
            if (!visit[i] && g->matrix[minV][i] < INFINITY)
            {
                if (g->matrix[minV][i] < 0)//���ڸ�ֱȦ
                    return false;
                if (distant[minV] + g->matrix[minV][i] < distant[i])
                {
                    distant[i] = distant[minV] + g->matrix[minV][i];
                    path[i] = minV;
                    //printf("\n����%s�ĵ��ǰһ������Ϊ%s",g->vertex[i].name,g->vertex[minV].name);
                }
            }
        }
    }
    return true;
}
void shortPath(Graph g, Position v, Position w, bool flag)
{
    int path[MAX_NODE];
    int distant[MAX_NODE];
    Position x = w;
    stack<Position> s;//�����������
    dijisktra(g, v, path, distant);//��dijisktra�㷨ȥ�������·���ĳ��� ���м�Ľ��
    if (distant[w] == INFINITY)//������·
    {
        printf("��%s��%s������·��\n", g->vertex[v].name, g->vertex[w].name);
        return;
    }
    printf("��%s��%s��·�� ���·������Ϊ%d\n", g->vertex[v].name, g->vertex[w].name, distant[w]);
    s.push(x);//����ѹջ
    while (path[x] != v)
    {
        x = path[x];
        s.push(x);
    }
    printf("\n");
    printf("%s", g->vertex[v].name);
    while (!s.empty())//�������
    {
        printf("->%s", g->vertex[s.top()].name);
        s.pop();
    }
    return;
}
void shortPath(Graph g, Position V, int max_distant)
{
    int path[MAX_NODE];
    int distant[MAX_NODE];
    int i, v;
    dijisktra(g, V, path, distant);
    stack<Position> s;//�ó�������˼·���� ֻ�ǽ�ָ����㻻Ϊ�������������Ľ��
    for (i = 0; i < g->vertex_num; ++i)
    {
        if (i != V && distant[i] < max_distant)
        {
            printf("\n��%s��%s��·�� ���·������Ϊ%d\n", g->vertex[V].name, g->vertex[i].name, distant[i]);
            v = i;
            s.push(v);
            while (path[v] != V)
            {
                v = path[v];
                s.push(v);
            }
            printf("%s", g->vertex[V].name);
            while (!s.empty())
            {
                printf("->%s", g->vertex[s.top()].name);
                s.pop();
            }
            printf("\n");
        }
    }
    return;
}
bool nameCmp(char* s, Scenery& t)
{
    return strstr(t.name, s) != NULL;//s�Ƿ�Ϊt���Ӵ�
}
bool markCmp(char* s, Scenery& t)
{
    return transToInt(s) == t.mark;
}
void search(Graph g, bool (*cmp)(char*, Scenery&))
{
    char s[MAX_LENGTH];
    int i, c = 0, mark[MAX_LENGTH] = { -1 };
    getLength(s, MAX_LENGTH);
    //printf("�㽫���ڲ�ѯ������%s\n",s);
    for (i = 0; i < g->vertex_num; i++)
    {
        if ((*cmp)(s, g->vertex[i]))//���ձ�Ż������ƽ��бȽ�
        {
            mark[c++] = i;
        }
    }
    printf("��ǰ��ѯ���Ľ����%d��\n", c);
    for (i = 0; i < c; i++)
    {
        printf("������%d-��������%s\t\n", mark[i], g->vertex[mark[i]].name);
    }
    return;
}
void searchName(Graph g)
{
    printf("������Ҫ��ѯ�ľ�������\n");
    search(g, nameCmp);
}
void searchMark(Graph g)
{
    printf("������Ҫ��ѯ�ľ�����\n");
    search(g, markCmp);
}
bool checkInformation(Graph g)
{
    system("title �ӱ���ѧУ԰����ϵͳ-��ѯ������Ϣ");
    system("cls");
    int op;
    bool isControl = true;
    do
    {
        printCheckInformation();
        op = getOp();
        switch (op)
        {
        case ERROR:
            printf("�������������\n");
            system("pause");
            break;
        case HELP:
            listOp();
            printf("\n");
            break;
        case EXIT:
            return false;
            break;
        case 1:
            print(g, false);//��ӡ��Ϣ
            system("pause");
            printCheckInformation();
            break;
        case 2:
            searchName(g);//����������
            system("pause");
            printCheckInformation();
            break;
        case 3:
            searchMark(g);//���������
            system("pause");
            printCheckInformation();
            break;
        case 4:
            return true;
            break;
        default:
            printf("�������������\n");
            system("pause");
        }
    } while (isControl);
    return true;
}
void searchShort(Graph g)
{
    system("cls");
    system("title �ӱ���ѧУ԰����ϵͳ-���·������");
    printf("��������������\n");
    printf("�����ŷ�ΧΪ%d��%d\n",0,g->vertex_num-1);
    char s[MAX_NODE_LENGTH];
    char t[MAX_NODE_LENGTH];
    Position v, w;
    bool flag = true;
    do
    {
        printf("�������һ������ı��\n");
        getLength(s, MAX_NODE_LENGTH);
        printf("��һ��������������� Ϊ%s\n", s);
        printf("������ڶ�������ı��\n");
        getLength(t, MAX_NODE_LENGTH);
        printf("�ڶ���������������� Ϊ%s\n", t);
        if (isNum(s) && isNum(t))//����������
        {
            //printf("��һ��%d �ڶ���%d",transToInt(s),transToInt(t));
            //�Ϸ����ж�
            if (transToInt(s) < 0 || transToInt(s) >= g->vertex_num || transToInt(t) < 0 || transToInt(t) >= g->vertex_num)
            {
                printf("�����ų�������Χ��������\n");
            }
            else
                flag = 0;
        }
        else
        {
            printf("��ǰ����Ϊ%s %s\n", s, t);
            printf("�����ʽ����,������\n");
        }
    } while (flag);
    v = transToInt(s);
    w = transToInt(t);
    printf("��Ҫ��ѯ������Ϊ%s,%s\n", g->vertex[v].name, g->vertex[w].name);
    shortPath(g, v, w, true);
    printf("\n\t�������\n");
    system("pause");
    system("cls");
    return;
}
void currentShortPath(Graph g)
{
    system("cls");
    system("title �ӱ���ѧУ԰����ϵͳ-��ǰ���㵽�������·");

    char s[MAX_NODE_LENGTH];
    bool flag = true;
    Position v;
    int dis = INFINITY;
    do
    {
        printf("����������ǰ���ڵľ�����\n");
        printf("�����ŷ�ΧΪ%d��%d\n",0,g->vertex_num-1);
        getLength(s, MAX_NODE_LENGTH);
        if (isNum(s))
        {//�Ϸ����ж�
            if (transToInt(s) < 0 || transToInt(s) >= g->vertex_num)
                printf("��ų�������Χ��������\n");
            else
                flag = false;
        }
        else
        {
            printf("��ǰ����Ϊ%s\n", s);
            printf("��ǰ��������������\n");
        }
    } while (flag);
    v = transToInt(s);
    printf("��Ҫ��ѯ�ľ���%s\n", g->vertex[v].name);
    shortPath(g, v, dis);//�������·
    system("pause");
}
bool visitorSystem(Graph g)//�ο�ϵͳ
{
    system("cls");
    system("title �ӱ���ѧУ԰����-�ο�ϵͳ");
    printVisitorInformation();
    int op;
    bool isControl = true;
    do
    {
        op = getOp();
        switch (op)
        {
        case ERROR:
            printf("�������������\n");
            system("pause");
            break;
        case HELP:
            listOp();
            printf("\n");
            break;
        case EXIT:
            return false;
            break;
        case 1:
            isControl = checkInformation(g);
            system("cls");
            printVisitorInformation();
            break;
        case 2:
            searchShort(g);
            system("cls");
            printVisitorInformation();
            break;
        case 3:
            currentShortPath(g);
            system("cls");
            printVisitorInformation();
            break;
        case 4:
            return true;
            break;
        default:
            printf("�������������\n");
            system("pause");
        }
    } while (isControl);
    //system("pause");
    return true;
}
bool checkPassword(char* password)//�������
{
    bool flag = true;
    char s[MAX_PASSWORD_LENGTH + 1];
    int c = 0;
    do
    {
        printf("���������Ա������\n��ʼ����Ϊ1234\n�˴���������cd exit\n");
        getLength(s, MAX_PASSWORD_LENGTH);
        if (strcmp(s, password))
        {
            if (c++ == 5)//��һ����
            {
                printf("���������̫�࣬�������ٴ��������룬ϵͳ���Զ�����\n");
                return  false;
            }
            printf("�����������������\n");
        }
        else
            flag = false;
    } while (flag);
    return true;
}
void modifyInformation(Graph g)//�޸���Ϣ
{
    system("cls");
    system("title �ӱ���ѧУ԰����-����Աϵͳ-�޸ľ�����Ϣ");
    printf("����������Ҫ�޸ĵľ��������\n");
    char s[MAX_NODE_LENGTH];
    char flag[2];//�����ж��Ƿ���Ҫ��ȡ
    char ab[MAX_ABSTRACT];
    int mark[MAX_NODE_LENGTH] = { -1 };
    int i, c = 0;

    getLength(s, MAX_NODE_LENGTH);
    for (i = 0; i < g->vertex_num; i++)
        if (nameCmp(s, g->vertex[i]))//ģ����ѯ �������еĶ�����һ�λ���
        {
            mark[c++] = i;
        }
    for (i = 0; i < c; i++)
    {
        printf("���ڵ�ǰ����%s����Ҫ�����޸�����Ϣ��������1������������ǰ������޸�\n", g->vertex[mark[i]].name);
        getLength(flag, 2);
        if (strcmp(flag, "1") == 0)//�����Ҫ�޸�
        {
            printf("���������Ľ��ܣ����ɳ���%d��\n", MAX_ABSTRACT - 1);
            getLength(ab, MAX_ABSTRACT);
            strcpy(g->vertex[mark[i]].abstract, ab);
            printf("��ǰ�����Ϣ�޸����\n");
        }
    }
    system("pause");
}
int readNode(int max_value)//����������ȡ�Ϸ�����
{
    char num[MAX_NODE_LENGTH];
    bool    flag = true;
    do
    {
        getLength(num, 3);
        if (isNum(num) && transToInt(num) < max_value && transToInt(num) >= 0)
            flag = false;
        else
        {
            //printf("%d %d %d %d\n",transToInt(num),isNum(num),transToInt(num)<max_value,transToInt(num)>=0);
            printf("����%s����,������\n", num);
        }

    } while (flag);
    return transToInt(num);
}
void addScenary(Graph g)//��Ӿ���
{
    system("cls");
    system("title �ӱ���ѧУ԰����-����Աϵͳ-���Ӿ���");
    if (MAX_NODE == g->vertex_num)//����Ѿ��޷�������
    {
        printf("��Ǹ����ǰ�������Ѵﵽ��࣬�޷���������\n");
        system("pause");
        return;
    }
    print(g);//���߱�����ʲô
    printf("\n");
    char name[MAX_NAME];
    char ab[MAX_ABSTRACT];
    int mark, dis;
    int how, j;
    //��ȡ�����Ϣ
    printf("����Ҫ���ӵľ���\n");
    printf("��Ϣ-����:\n");
    getLength(name, MAX_NAME);
    strcpy(g->vertex[g->vertex_num].name, name);
    printf("��Ϣ-����:\n");
    getLength(ab, MAX_ABSTRACT);
    strcpy(g->vertex[g->vertex_num].abstract, ab);
    for (j = 0; j < g->vertex_num; j++)
        g->matrix[g->vertex_num][j] = INFINITY;
    printf("������þ���ɵ�����ٸ�����\n");
    how = readNode(g->vertex_num);
    for (j = 0; j < how; j++)
    {
        printf("�ɵ���ĵ�%d������\n", j + 1);
        printf("������þ�����\n");
        mark = readNode(g->vertex_num - 1);
        printf("���������֮��ľ���\n");
        dis = readNode(1000);
        g->matrix[g->vertex_num][mark] = g->matrix[mark][g->vertex_num] = dis;
        printf("�������\n");
    }
    g->vertex_num++;//��������1
    system("pause");
    return;
}
void deleteScenary(Graph g)//ɾ������
{
    system("cls");
    system("title �ӱ���ѧУ԰����-����Աϵͳ-ɾ������");
    if (0 == g->vertex_num)
    {
        printf("��Ǹ����ǰ�����ھ��㣬�޷�ɾ��\n");
        system("pause");
        return;
    }
    print(g);
    printf("\n");
    int mark, i;
    printf("��������Ҫɾ���ľ���ı��\n");
    mark = readNode(g->vertex_num);
    //�����һ��������������������Ϣ���� Ȼ��ɾ�����һ��
    g->vertex[g->vertex_num - 1].mark = g->vertex[mark].mark;
    swap(g->vertex[mark], g->vertex[g->vertex_num - 1]);
    for (i = 0; i < g->vertex_num; i++)
    {
        swap(g->matrix[mark][i], g->matrix[g->vertex_num - 1][i]);
    }
    g->vertex_num--;
    printf("ɾ�����\n");
    system("pause");
    return;
}
void addRoad(Graph g)//���·
{
    system("cls");
    system("title �ӱ���ѧУ԰����-����Աϵͳ-���ӵ�·");
    print(g);
    printf("\n");
    printf("����������Ҫ����һ��·�������յ�\n");
    int begin, end, dis;
    printf("�������һ������ı��\n");
    begin = readNode(g->vertex_num);
    printf("������ڶ�������ı��\n");
    end = readNode(g->vertex_num);
    printf("������������·֮��ľ���\n");
    dis = readNode(1500);//����һ�¾��� �ӱ���ѧ��û��ô����
    g->matrix[begin][end] = g->matrix[end][begin] = dis;
    printf("�������һ��· ��%s��%s ����Ϊ%d��\n", g->vertex[begin].name, g->vertex[end].name, dis);
    g->edge_num++;
    system("pause");
}
void deleteRoad(Graph g)//ɾ��·
{
    system("cls");
    system("title �ӱ���ѧУ԰����-����Աϵͳ-ɾ����·");
    print(g);
    printf("\n");//��ȡ������Ϣɾ������
    printf("����������Ҫɾ��һ��·�������յ�\n");
    int begin, end;
    printf("�������һ������ı��\n");
    begin = readNode(g->vertex_num);
    printf("������ڶ�������ı��\n");
    end = readNode(g->vertex_num);
    g->matrix[begin][end] = g->matrix[end][begin] = INFINITY;
    printf("��ɾ����һ��· ��%s��%s\n", g->vertex[begin].name, g->vertex[end].name);
    g->edge_num--;
    system("pause");
}
bool managerSystem(Graph g, char* password)//����Աϵͳ
{
    system("cls");
    system("title �ӱ���ѧУ԰����-����Աϵͳ");

    if (checkPassword(password))//���ȵ��ж��Ƿ�����ͨ��
    {
        system("cls");
        printManagerSystem();
        int op;
        bool isControl = true;
        do
        {
            op = getOp();
            switch (op)
            {
            case ERROR:
                printf("�������������\n");
                system("pause");
                printManagerSystem();
                break;
            case HELP:
                listOp();
                printf("\n");
                break;
            case EXIT:
                return false;
                break;
            case 1:
                isControl = checkInformation(g);
                system("pause");
                system("cls");
                printManagerSystem();
                break;
            case 2:
                searchShort(g);
                system("cls");
                printManagerSystem();
                break;
            case 3:
                currentShortPath(g);
                system("cls");
                printManagerSystem();
                break;
            case 4:
                modifyInformation(g);
                system("cls");
                printManagerSystem();
                break;
            case 5:
                addScenary(g);
                system("cls");
                printManagerSystem();
                break;
            case 6:
                deleteScenary(g);
                system("cls");
                printManagerSystem();
                break;
            case 7:
                addRoad(g);
                system("cls");
                printManagerSystem();
                break;
            case 8:
                deleteRoad(g);
                system("cls");
                printManagerSystem();
                break;
            case 9:
                return true;
                break;
            default:
                printf("�������������\n");
                system("pause");
            }
        } while (isControl);
    }
    system("cls");
    return true;
}
