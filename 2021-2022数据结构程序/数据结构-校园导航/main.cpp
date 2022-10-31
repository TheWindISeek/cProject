#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stack>
//const define
//操作数最大长度
//名称最大长度
//描述最大长度
//最大的结点个数
//结点数字的长度
//密码最大长度
//无穷大
//无法到达
//退出
//错误
//帮助
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
typedef int Weight;//权值
typedef int Position;//位置
typedef struct graph* Graph;//图结构指针
typedef struct//每个景点的结构体
{
    int mark;//代号
    char name[MAX_NODE];//名称
    char abstract[MAX_NODE];//简介
} Scenery;
struct graph//这个图
{
    int vertex_num;//结点个数
    int edge_num;//边个数
    Weight matrix[MAX_NODE][MAX_NODE];//邻接矩阵存储的有权图
    Scenery vertex[MAX_NODE];//每个景点的信息
};
//function declare

//图相关操作
Graph creatGraph(int, int);//创建一个图
inline void print(Graph);//打印所有结点的信息 包括简介
void print(Graph, bool);//打印图 bool用于控制是否输出简介
inline void print(Graph, Position, bool);//打印对应结点的信息 bool用于控制是否打印简介
inline void print(Graph, Position, Position);//打印从第一个点到第二个点的信息

//输入输出函数
int getOp();//类似于命令行 返回的是相对应的操作数如之前的HELP 输入Cd 或者cd都可以 提高容错
char* transToLower(char*);//将输入字符串变为小写 返回输入字符串
void listOp();//列出所有命令集的情况
bool isNum(char*);//判断一个字符串是否是数字
int transToInt(char*);//将一个字符串转换成数字bool
bool visitorSystem(Graph);//游客系统的函数 返回的是是否退出程序的标志变量
int readNode(int);//int用于限制读取数据的最大数值 返回一个从输入流里读取的整数
char* getLength(char*,int);//从输入流读取指定长度字符串到给定字符串上

//具体模块函数
bool managerSystem(Graph, char*);//管理员系统 返回的是是否退出程序的标志
bool checkInformation(Graph);//搜索景点信息的模块
void searchShort(Graph);//搜索最短路模块
void currentShortPath(Graph);//当前结点到其他点的最短路
void searchName(Graph);//搜索名称 支持模糊查询
void searchMark(Graph);//搜索编号 不支持模糊查询
void search(Graph, bool(*)(char*, Scenery&));//搜索模块 名称与编号的不同仅在于比较的不同
bool nameCmp(char*, Scenery&);//用于比较名称的函数
bool markCmp(char*, Scenery&);//用于比较编号的函数
void modifyInformation(Graph);//修改景点信息模块
void addScenary(Graph);//添加景点 直接在结点之后添加
void deleteScenary(Graph);//将要删除的这个结点的所有数据与最后的一个结点数据进行交换然后删除最后一个结点就行了 因为我的结点都是按编号排序的 但是编号并没有什么实际意义 所以交换编号的位置无所谓
void addRoad(Graph);//添加道路模块
void deleteRoad(Graph);//删除道路模块
bool checkPassword(char*);//判断这个字符串是否是密码
void shortPath(Graph, Position, int);//当前景点是否显示路径 int用于限制长度
void shortPath(Graph, Position, Position, bool);//打印任意两个景点之间的最短路径 bool用于控制是否输出具体路径

//核心函数
bool dijisktra(Graph, Position, int[], int[]);//求最短路的算法 传入参数 图 结点 记录路径的数组 记录距离的数组 返回成功标准
//每个系统的提示信息
void printMainInformation();
void printVisitorInformation();
void printManagerSystem();
void printCheckInformation();
int main()
{
    Graph g = creatGraph(31, 56);//按照给定数据生成的图
    int op;
    char  password[MAX_PASSWORD_LENGTH] = "1234";//初始密码
    bool isControl = true;//用于控制循环的变量
    system("title 河北大学校园导航系统-主页面");
        printf("————欢迎来到河北大学校园导航系统\n");
        printf("请选择你将要进行的操作\n");
        printf("1.游客系统\n");
        printf("2.管理员系统\n");
        printf("3.退出导航系统\n");
        printf("如需提供帮助,请输入help\n请勿多次点击\n操作示范!!!\ncd 回车 1 回车\nhelp\nexit\n请不要多输入空格 否则将会直接退出系统\n");
    do
    {

        //printf("如需提供帮助,请输入help\n请勿多次点击\n操作示范!!!\ncd 回车 1 回车\nhelp\nexit\n请不要多输入空格 否则将会直接退出系统\n");
        isControl = true;
        op = getOp();//从输入流获得操作数
        switch (op)
        {
        case ERROR:
            printf("输入错误，请重新输入\n");
            system("pause");
            break;
        case HELP:
            listOp();
            printf("\n");
            break;
        case EXIT:
            exit(0);
            break;
        case 1://游客模块
            isControl = visitorSystem(g);
            system("cls");
            printMainInformation();
            break;
        case 2://管理员模块
            isControl = managerSystem(g, password);
            system("cls");
            printMainInformation();
            break;
        case 3://直接退出
            exit(0);
            break;
        default:
            printf("输入错误，请重输\n");
            system("pause");
        }
    } while (isControl);
    return 0;
}
void printMainInformation(){
        system("title 河北大学校园导航系统-主页面");
        printf("————欢迎来到河北大学校园导航系统\n");
        printf("请选择你将要进行的操作\n");
        printf("1.游客系统\n");
        printf("2.管理员系统\n");
        printf("3.退出导航系统\n");
        printf("如需提供帮助,请输入help\n请勿多次点击\n操作示范!!!\ncd 回车 1 回车\nhelp\nexit\n请不要多输入空格 否则将会直接退出系统\n");
}
void printVisitorInformation(){
        printf("————欢迎来到游客系统\n");
        printf("1.查询景点信息\n");
        printf("2.任意两景点之间最短路径\n");
        printf("3.当前景点到其他景点的最短路径\n");
        printf("4.返回上一级系统\n");
        printf("如需提供帮助,请输入help\n请勿多次点击\n操作示范!!!\ncd 回车 1 回车\nhelp\nexit\n请不要多输入空格 否则将会直接退出系统\n");
}
void printManagerSystem(){
            printf("————欢迎来到管理员系统\n");
            printf("1.查询景点信息\n");
            printf("2.任意两景点之间最短路径\n");
            printf("3.当前景点到其他景点的最短路径\n");
            printf("4.修改景点信息\n");
            printf("5.增加景点\n");
            printf("6.删除景点\n");
            printf("7.增加道路\n");
            printf("8.删除道路\n");
            printf("9.返回上一级系统\n");
            printf("如需提供帮助,请输入help\n请勿多次点击\n操作示范!!!\ncd 回车 1 回车\nhelp\nexit\n请不要多输入空格 否则将会直接退出系统\n");
}
void printCheckInformation(){
        printf("1.整个学校的景点信息\n");
        printf("2.选择名称进行查询\n");
        printf("3.选择编号进行查询\n");
        printf("4.返回上一级系统\n");
        printf("如需提供帮助,请输入help\n请勿多次点击\n操作示范!!!\ncd 回车 1 回车\nhelp\nexit\n请不要多输入空格 否则将会直接退出系统\n");
}
int transToInt(char* s)//将这个字符串转换为int类型
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
bool isNum(char* s)//判断这个字符串是否是数字
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
char* transToLower(char* s)//将字符串转换为小写
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
char* getLength(char* s, int length)//从输入流中读取最大长度为length的数据到s中
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
void listOp()//帮助输出
{
    printf("请先输入将要进行的操作\n");
    printf("如想进行某项操作先输入cd 再输入将要进行的操作对应的编号 如cd 回车 1 回车\n");
    printf("如想获取帮助 请输入help\n");
    printf("如想退出系统 请输入exit\n");
    printf("以上仅在存在操作编号的情况下使用，其余情况按要求输入即可\n");
    system("pause");
}
int emptyStream()//清空输入缓冲区
{
    char c;
    while ((c = getchar()) != '\n');
    return 1;
}
int getOp()//获得操作数
{
    char s[MAX_LENGTH];//选择何种操作
    char op[MAX_LENGTH];//数字读取
    getLength(s, MAX_LENGTH);
    //cin.getline(s,MAX_LENGTH,' ');
    //emptyStream();
    transToLower(s);//转换为小写 提高容错
    //printf("这是得到的结果%s\n",s);
    if (strcmp(s, "cd") == 0)//cd操作
    {
        printf("请输入想要进行的操作\n");
        getLength(op, MAX_LENGTH);//读取数据
        //cin.getline(op,MAX_LENGTH,'\n');
        //printf("这是得到的第二个字符串%s",op);
        //emptyStream();
        if (isNum(op))//如果是数字 就直接返回对应的数字 否则告诉输入错误
            return transToInt(op);
        else
            return ERROR;
    }
    else if (strcmp(s, "help") == 0)
    {
        printf("这是帮助");
        return HELP;
    }
    else if (strcmp(s, "exit") == 0)
    {
        return EXIT;
    }
    else//最开始的操作就错误了
    {
        emptyStream();//
        return ERROR;
    }
}
Graph creatGraph(int vertex_num, int edge_num)//按照给定的结点数 边数创建数据
{
    Graph g = (Graph)malloc(sizeof(struct graph));
    g->vertex_num = vertex_num;
    g->edge_num = edge_num;
    int i, j;
    //先初始化为无穷
    for (i = 0; i < MAX_NODE; i++)
        for (j = 0; j < MAX_NODE; j++)
            g->matrix[i][j] = INFINITY;
    /*以下为给定的初始数据*/
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
    char dresnam[MAX_NODE][MAX_NAME] = { "校医院","生科院","建工学院","理化中心","逸夫楼","宿舍梅园6号","北院餐厅","化学学院","物理学院","南2门口",
                                        "宿舍梅园3、4、5号","篮球场网球场","电信学院","竟学楼","南1门口","宿舍梅园2号","操场","学生宿舍梅园1号",
                                        "北1门口","北2门口","图书馆","文苑楼","多功能馆","主楼","第九教学楼","第八教学楼","南院餐厅","毓秀园","国际交流学院","综合教学楼","第七教学楼"
    };
    char dresinfo[MAX_NODE][MAX_ABSTRACT] = { "生病就去这里","生命科学学院","建筑与工程学院","物理化学中心","自习用",
                                              "宿舍","北边的餐厅","化学科学学院","物理科学学院","前往南面的第2个门口","宿舍",
                                              "打球的地方","电子信息学院","自习用","前往南面的第1个门口","宿舍","跑步用","宿舍",
                                              "前往北边的第1个门口","前往北边的第2个门口", "看书的地方","自习用","健身用",
                                              "自习用","自习用","自习用","南面吃饭的","宿舍","不知道",
                                              "自习用","自习用"
    };
    for (i = 0; i < MAX_NODE; i++)
    {
        strcpy(g->vertex[i].abstract, dresinfo[i]);
        strcpy(g->vertex[i].name, dresnam[i]);
        g->vertex[i].mark = i;
    }

    return g;
}
inline void print(Graph g, Position v, bool check)//打印具体某个结点的数据 这是用于后续输出的小函数 精简程序用
{
    if (check)
        printf("%2d:%5s\t", g->vertex[v].mark, g->vertex[v].name);
    else
        printf("%2d:%5s %6s\t", g->vertex[v].mark, g->vertex[v].name, g->vertex[v].abstract);
}
void print(Graph g, bool check)//输出所有结点的信息 check控制是否需要输出简介
{
    int j = 3;
    Position i;
    printf("\t以下为整个学校所有的景点\t\n他们的格式按如下方式给出 景点编号：景点名称");
    for (i = 0; i != g->vertex_num; i++)
    {
        if (++j == 4)
        {
            printf("\n第%d行|\t", (i / 4) + 1);
            j = 0;
        }
        print(g, i, check);
    }
    printf("\n\t总共有%d个景点", g->vertex_num);
}
inline void print(Graph g)//打印所有结点的信息
{
    print(g, true);
}
bool dijisktra(Graph g, Position v, int path[], int distant[])//核心的dijistra算法
{
    int visit[MAX_NODE] = { 0 };//所有的结点都没有被访问
    int i, j;//用于循环的变量
    Position minV;//记录最小点的下标
    int minDistant = INFINITY;//最短距离标记为无穷大
    for (i = 0; i < g->vertex_num; i++)
    {
        distant[i] = g->matrix[v][i];//初始化距离
        if (g->matrix[v][i] != INFINITY)//能到 就把上个点设置为源点
            path[i] = v;
        else//如果不能到达 就标记为不能到达
            path[i] = NotReach;
    }
    //收录源点
    distant[v] = 0;
    visit[v] = 1;
    while (1)
    {
        minV = NotReach;//无法到达
        minDistant = INFINITY;//无穷远
        for (j = 0; j < g->vertex_num; j++)//查找最低的结点
            if (!visit[j] && distant[j] < minDistant)
            {
                minV = j;
                minDistant = distant[j];
            }
        if (minDistant == INFINITY)//找不到了就退出
            break;
        visit[minV] = 1;//标记这个结点
        for (i = 0; i < g->vertex_num; i++)//更新结点
        {
            if (!visit[i] && g->matrix[minV][i] < INFINITY)
            {
                if (g->matrix[minV][i] < 0)//存在负直圈
                    return false;
                if (distant[minV] + g->matrix[minV][i] < distant[i])
                {
                    distant[i] = distant[minV] + g->matrix[minV][i];
                    path[i] = minV;
                    //printf("\n将第%s的点的前一个更新为%s",g->vertex[i].name,g->vertex[minV].name);
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
    stack<Position> s;//用于正向输出
    dijisktra(g, v, path, distant);//用dijisktra算法去计算最短路径的长度 和中间的结点
    if (distant[w] == INFINITY)//不存在路
    {
        printf("从%s到%s不存在路径\n", g->vertex[v].name, g->vertex[w].name);
        return;
    }
    printf("从%s到%s的路径 最短路径长度为%d\n", g->vertex[v].name, g->vertex[w].name, distant[w]);
    s.push(x);//逆序压栈
    while (path[x] != v)
    {
        x = path[x];
        s.push(x);
    }
    printf("\n");
    printf("%s", g->vertex[v].name);
    while (!s.empty())//正序输出
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
    stack<Position> s;//该程序整体思路如上 只是将指定结点换为所有满足条件的结点
    for (i = 0; i < g->vertex_num; ++i)
    {
        if (i != V && distant[i] < max_distant)
        {
            printf("\n从%s到%s的路径 最短路径长度为%d\n", g->vertex[V].name, g->vertex[i].name, distant[i]);
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
    return strstr(t.name, s) != NULL;//s是否为t的子串
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
    //printf("你将用于查询的名称%s\n",s);
    for (i = 0; i < g->vertex_num; i++)
    {
        if ((*cmp)(s, g->vertex[i]))//按照编号或者名称进行比较
        {
            mark[c++] = i;
        }
    }
    printf("当前查询到的结果有%d个\n", c);
    for (i = 0; i < c; i++)
    {
        printf("景点编号%d-景点名称%s\t\n", mark[i], g->vertex[mark[i]].name);
    }
    return;
}
void searchName(Graph g)
{
    printf("请输入要查询的景点名称\n");
    search(g, nameCmp);
}
void searchMark(Graph g)
{
    printf("请输入要查询的景点编号\n");
    search(g, markCmp);
}
bool checkInformation(Graph g)
{
    system("title 河北大学校园导航系统-查询景点信息");
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
            printf("输入错误，请重输\n");
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
            print(g, false);//打印信息
            system("pause");
            printCheckInformation();
            break;
        case 2:
            searchName(g);//按名称搜索
            system("pause");
            printCheckInformation();
            break;
        case 3:
            searchMark(g);//按编号搜索
            system("pause");
            printCheckInformation();
            break;
        case 4:
            return true;
            break;
        default:
            printf("输入错误，请重输\n");
            system("pause");
        }
    } while (isControl);
    return true;
}
void searchShort(Graph g)
{
    system("cls");
    system("title 河北大学校园导航系统-最短路径搜索");
    printf("请输入俩景点编号\n");
    printf("输入编号范围为%d到%d\n",0,g->vertex_num-1);
    char s[MAX_NODE_LENGTH];
    char t[MAX_NODE_LENGTH];
    Position v, w;
    bool flag = true;
    do
    {
        printf("请输入第一个景点的编号\n");
        getLength(s, MAX_NODE_LENGTH);
        printf("第一个景点编号输入完毕 为%s\n", s);
        printf("请输入第二个景点的编号\n");
        getLength(t, MAX_NODE_LENGTH);
        printf("第二个景点编号输入完毕 为%s\n", t);
        if (isNum(s) && isNum(t))//首先是数字
        {
            //printf("第一个%d 第二个%d",transToInt(s),transToInt(t));
            //合法性判断
            if (transToInt(s) < 0 || transToInt(s) >= g->vertex_num || transToInt(t) < 0 || transToInt(t) >= g->vertex_num)
            {
                printf("输入编号超出合理范围，请重输\n");
            }
            else
                flag = 0;
        }
        else
        {
            printf("当前输入为%s %s\n", s, t);
            printf("输入格式有误,请重输\n");
        }
    } while (flag);
    v = transToInt(s);
    w = transToInt(t);
    printf("将要查询的两点为%s,%s\n", g->vertex[v].name, g->vertex[w].name);
    shortPath(g, v, w, true);
    printf("\n\t运行完毕\n");
    system("pause");
    system("cls");
    return;
}
void currentShortPath(Graph g)
{
    system("cls");
    system("title 河北大学校园导航系统-当前景点到其他最短路");

    char s[MAX_NODE_LENGTH];
    bool flag = true;
    Position v;
    int dis = INFINITY;
    do
    {
        printf("请输入您当前所在的景点编号\n");
        printf("输入编号范围为%d到%d\n",0,g->vertex_num-1);
        getLength(s, MAX_NODE_LENGTH);
        if (isNum(s))
        {//合法性判断
            if (transToInt(s) < 0 || transToInt(s) >= g->vertex_num)
                printf("编号超出合理范围，请重输\n");
            else
                flag = false;
        }
        else
        {
            printf("当前输入为%s\n", s);
            printf("当前输入有误，请重输\n");
        }
    } while (flag);
    v = transToInt(s);
    printf("将要查询的景点%s\n", g->vertex[v].name);
    shortPath(g, v, dis);//运行最短路
    system("pause");
}
bool visitorSystem(Graph g)//游客系统
{
    system("cls");
    system("title 河北大学校园导航-游客系统");
    printVisitorInformation();
    int op;
    bool isControl = true;
    do
    {
        op = getOp();
        switch (op)
        {
        case ERROR:
            printf("输入错误，请重输\n");
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
            printf("输入错误，请重输\n");
            system("pause");
        }
    } while (isControl);
    //system("pause");
    return true;
}
bool checkPassword(char* password)//检查密码
{
    bool flag = true;
    char s[MAX_PASSWORD_LENGTH + 1];
    int c = 0;
    do
    {
        printf("请输入管理员的密码\n初始密码为1234\n此处无须输入cd exit\n");
        getLength(s, MAX_PASSWORD_LENGTH);
        if (strcmp(s, password))
        {
            if (c++ == 5)//加一个锁
            {
                printf("您错误次数太多，将不能再次输入密码，系统将自动返回\n");
                return  false;
            }
            printf("输入错误请重新输入\n");
        }
        else
            flag = false;
    } while (flag);
    return true;
}
void modifyInformation(Graph g)//修改信息
{
    system("cls");
    system("title 河北大学校园导航-管理员系统-修改景点信息");
    printf("请输入您将要修改的景点的名称\n");
    char s[MAX_NODE_LENGTH];
    char flag[2];//用于判断是否还需要读取
    char ab[MAX_ABSTRACT];
    int mark[MAX_NODE_LENGTH] = { -1 };
    int i, c = 0;

    getLength(s, MAX_NODE_LENGTH);
    for (i = 0; i < g->vertex_num; i++)
        if (nameCmp(s, g->vertex[i]))//模糊查询 对于所有的都给予一次机会
        {
            mark[c++] = i;
        }
    for (i = 0; i < c; i++)
    {
        printf("对于当前景点%s，你要是想修改其信息，请输入1，否则将跳过当前景点的修改\n", g->vertex[mark[i]].name);
        getLength(flag, 2);
        if (strcmp(flag, "1") == 0)//如果还要修改
        {
            printf("请输入对其的介绍，不可超过%d字\n", MAX_ABSTRACT - 1);
            getLength(ab, MAX_ABSTRACT);
            strcpy(g->vertex[mark[i]].abstract, ab);
            printf("当前结点信息修改完成\n");
        }
    }
    system("pause");
}
int readNode(int max_value)//从输入流读取合法数字
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
            printf("输入%s有误,请重输\n", num);
        }

    } while (flag);
    return transToInt(num);
}
void addScenary(Graph g)//添加景点
{
    system("cls");
    system("title 河北大学校园导航-管理员系统-增加景点");
    if (MAX_NODE == g->vertex_num)//如果已经无法再增加
    {
        printf("抱歉，当前景点数已达到最多，无法再增加了\n");
        system("pause");
        return;
    }
    print(g);//告诉别人有什么
    printf("\n");
    char name[MAX_NAME];
    char ab[MAX_ABSTRACT];
    int mark, dis;
    int how, j;
    //读取相关信息
    printf("您将要增加的景点\n");
    printf("信息-名称:\n");
    getLength(name, MAX_NAME);
    strcpy(g->vertex[g->vertex_num].name, name);
    printf("信息-描述:\n");
    getLength(ab, MAX_ABSTRACT);
    strcpy(g->vertex[g->vertex_num].abstract, ab);
    for (j = 0; j < g->vertex_num; j++)
        g->matrix[g->vertex_num][j] = INFINITY;
    printf("请输入该景点可到达多少个景点\n");
    how = readNode(g->vertex_num);
    for (j = 0; j < how; j++)
    {
        printf("可到达的第%d个景点\n", j + 1);
        printf("请输入该景点编号\n");
        mark = readNode(g->vertex_num - 1);
        printf("请输入二者之间的距离\n");
        dis = readNode(1000);
        g->matrix[g->vertex_num][mark] = g->matrix[mark][g->vertex_num] = dis;
        printf("输入完成\n");
    }
    g->vertex_num++;//结点个数加1
    system("pause");
    return;
}
void deleteScenary(Graph g)//删除景点
{
    system("cls");
    system("title 河北大学校园导航-管理员系统-删除景点");
    if (0 == g->vertex_num)
    {
        printf("抱歉，当前不存在景点，无法删除\n");
        system("pause");
        return;
    }
    print(g);
    printf("\n");
    int mark, i;
    printf("请输入您要删除的景点的编号\n");
    mark = readNode(g->vertex_num);
    //将最后一个结点与这个结点的所有信息互换 然后删除最后一个
    g->vertex[g->vertex_num - 1].mark = g->vertex[mark].mark;
    swap(g->vertex[mark], g->vertex[g->vertex_num - 1]);
    for (i = 0; i < g->vertex_num; i++)
    {
        swap(g->matrix[mark][i], g->matrix[g->vertex_num - 1][i]);
    }
    g->vertex_num--;
    printf("删除完成\n");
    system("pause");
    return;
}
void addRoad(Graph g)//添加路
{
    system("cls");
    system("title 河北大学校园导航-管理员系统-增加道路");
    print(g);
    printf("\n");
    printf("请输入您将要增加一条路的起点和终点\n");
    int begin, end, dis;
    printf("请输入第一个景点的编号\n");
    begin = readNode(g->vertex_num);
    printf("请输入第二个景点的编号\n");
    end = readNode(g->vertex_num);
    printf("请输入这两条路之间的距离\n");
    dis = readNode(1500);//限制一下距离 河北大学还没那么大呢
    g->matrix[begin][end] = g->matrix[end][begin] = dis;
    printf("新输入的一条路 从%s到%s 距离为%d米\n", g->vertex[begin].name, g->vertex[end].name, dis);
    g->edge_num++;
    system("pause");
}
void deleteRoad(Graph g)//删除路
{
    system("cls");
    system("title 河北大学校园导航-管理员系统-删除道路");
    print(g);
    printf("\n");//读取所有信息删除即可
    printf("请输入您将要删除一条路的起点和终点\n");
    int begin, end;
    printf("请输入第一个景点的编号\n");
    begin = readNode(g->vertex_num);
    printf("请输入第二个景点的编号\n");
    end = readNode(g->vertex_num);
    g->matrix[begin][end] = g->matrix[end][begin] = INFINITY;
    printf("新删除的一条路 从%s到%s\n", g->vertex[begin].name, g->vertex[end].name);
    g->edge_num--;
    system("pause");
}
bool managerSystem(Graph g, char* password)//管理员系统
{
    system("cls");
    system("title 河北大学校园导航-管理员系统");

    if (checkPassword(password))//首先得判断是否密码通过
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
                printf("输入错误，请重输\n");
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
                printf("输入错误，请重输\n");
                system("pause");
            }
        } while (isControl);
    }
    system("cls");
    return true;
}
