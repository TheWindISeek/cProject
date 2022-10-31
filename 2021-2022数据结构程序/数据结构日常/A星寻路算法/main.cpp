#include <iostream>
#include <list>
#include <vector>
#include <queue>

struct OpenPoint{
    int x;
    int y;
    int cost;                 // �ķ�ֵ
    int pred;                 // Ԥ��ֵ
    OpenPoint* father;        // ���ڵ�
    OpenPoint() = default;
    OpenPoint(int pX,int pY, int endX, int endY, int c, OpenPoint* fatherp) : x(pX),y(pY),cost(c), father(fatherp) {
        //���λ��x,yȡ����ֵ
        int relativeX = std::abs(endX - pX);
        int relativeY = std::abs(endY - pY);
        //x,yƫ��ֵn
        int n = relativeX - relativeY;
        //Ԥ��ֵpred = (max�Cn)*14+n*10+c
        pred = std::max(relativeX, relativeY) * 14 - std::abs(n) * 4 + c;
    }
};

//�Ƚ������������ȶ��е�ָ�����ͱȽ�
struct OpenPointPtrCompare {
    bool operator()(OpenPoint* a, OpenPoint* b) {
        return a->pred > b->pred;
    }
};

const int width = 30;            //��ͼ����
const int height = 100;          //��ͼ�߶�
char mapBuffer[width][height];   //��ͼ����
int depth = 0;                   //��¼���
const int depthLimit = 2000;     //�������
bool closeAndBarrierList[width][height];    //��¼�ϰ���+�رյ�Ķ�ά��
//�˷���λ��
int direction[8][2] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{ -1,1 },{ -1,-1 },{ 1,-1 } };
//ʹ��������ȶ���
std::priority_queue<OpenPoint*, std::vector<OpenPoint*>, OpenPointPtrCompare> openlist;
//�洢OpenPoint���ڴ�ռ�
std::vector<OpenPoint> pointList = std::vector<OpenPoint>(depthLimit);

//�Ƿ����ϰ�����߹ر��б�
inline bool inBarrierAndCloseList(int pX,int pY) {
    if (pX < 0 || pY < 0 || pX >= width || pY >= height)
        return true;
    return closeAndBarrierList[pX][pY];
}

//����һ��������
inline OpenPoint* createOpenPoint(int pX,int pY,int endX,int endY, int c, OpenPoint* fatherp) {
    pointList.emplace_back(pX,pY,endX,endY, c, fatherp);
    return &pointList.back();
}

// ������飬��鸸�ڵ�
void open(OpenPoint& pointToOpen, int endX,int endY) {
    //�����ڵ��openlist�Ƴ�
    openlist.pop();
    //���+1
    depth++;
    //���p��˷��ĵ�
    for (int i = 0; i < 4; ++i)
    {
        int toOpenX = pointToOpen.x + direction[i][0];
        int toOpenY = pointToOpen.y + direction[i][1];
        if (!inBarrierAndCloseList(toOpenX,toOpenY)) {
            openlist.push(createOpenPoint(toOpenX, toOpenY, endX,endY, pointToOpen.cost + 10, &pointToOpen));
        }
    }
    for (int i = 4; i < 8; ++i)
    {
        int toOpenX = pointToOpen.x + direction[i][0];
        int toOpenY = pointToOpen.y + direction[i][1];
        if (!inBarrierAndCloseList(toOpenX, toOpenY)) {
            openlist.push(createOpenPoint(toOpenX, toOpenY, endX, endY, pointToOpen.cost + 14, &pointToOpen));
        }
    }
    //�������closelist
    closeAndBarrierList[pointToOpen.x][pointToOpen.y] = true;
}

//��ʼ����·��
std::list<OpenPoint*> findway(int startX,int startY, int endX,int endY) {
    std::list<OpenPoint*> road;
    // ����������һ�����ڵ�
    openlist.push(createOpenPoint(startX,startY, endX,endY, 0, nullptr));
    OpenPoint* toOpen = nullptr;
    //�ظ�Ѱ��Ԥ��ͻ���֮����С�ڵ㿪�����
    while (!openlist.empty())
    {
        toOpen = openlist.top();
        // �ҵ��յ����ֹͣ����
        if (toOpen->x == endX && toOpen->y ==endY) {break;}//������һ�����(1000���)��������ʧ��
        if (depth >= depthLimit) {
            toOpen = nullptr;
            break;
        }
        open(*toOpen, endX,endY);
    }
    for (auto rs = toOpen; rs != nullptr; rs = rs->father) {road.push_back(rs);}
    return road;
}

//������ͼ
void createMap() {
    for (int i = 0; i < width; ++i)
        for (int j = 0; j < height; ++j) {
            //���֮һ���������ϰ��������
            if (rand() % 5 == 0) {
                mapBuffer[i][j] = '*';
                closeAndBarrierList[i][j] = true;
            }
            else {
                mapBuffer[i][j] = ' ';
                closeAndBarrierList[i][j] = false;
            }
        }
}

//��ӡ��ͼ
void printMap() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j)
            std::cout << mapBuffer[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
}

int main() {
    //���
    int beginX = 0;
    int beginY = 0;
    //�յ�
    int endX = 29;
    int endY = 99;
    //������ͼ
    createMap();
    //��֤�����յ㶼�����ϰ���
    mapBuffer[beginX][beginY] = mapBuffer[endX][endY] = ' ';
    closeAndBarrierList[beginX][beginY] = closeAndBarrierList[endX][endY] = false;
    //A*�����õ�һ��·��
    std::list<OpenPoint*> road = findway(beginX,beginY,endX,endY);
    //��A*������·�������ĵ���Ϊ'O'
    for (auto& p : road){mapBuffer[p->x][p->y] = 'O';}
    //��ӡ�߹�·��ĵ�ͼ
    printMap();
    system("pause");
    return 0;
}
