#include <bits/stdc++.h>
using namespace std;
const int LEN = 362880;//9!
struct node {
    int state[9];//״̬
    int dis;//����
};
int dir[4][2]= {
    {-1,0},{0,-1},{1,0},{0,1}//��������
};

int visited[LEN] = {0};//��������
int start[9];//���״̬
int goal[9];//����״̬
long int factory[] = {1,1,2,6,24,120,720,5040,40320,362880};//0! - 9!

bool Cantor(int str[],int n)
{
    long result = 0;//���ڼ�����ǽ׳� ��ֹԽ��
    for(int i = 0; i < n; ++i) {
        int counted = 0;//��ǰ������ִ����ĸ�λ��
        for(int j = i+1; j <n; j++) {
            if(str[i] > str[j])
                ++counted;
        }
        result += counted * factory[n-i-1];//����λ��
    }
    if(!visited[result]) {//û�з��ʹ� ����
        visited[result] = 1;
        return 1;
    } else//�Ѿ����ʹ���
        return 0;
}
int bfs()
{
    node head;
    memcpy(head.state,start,sizeof(head.state));//�ڴ濽�� �����ʼ���
    head.dis = 0;//������Ϊ0
    queue<node> q;//����
    Cantor(head.state,9);//����ѷ���
    q.push(head);

    while(!q.empty()) {
        head = q.front();
        q.pop();
        int z;
        for(z = 0; z < 9; ++z)//�ҵ�0��λ�� ת��0��λ��
            if(head.state[z] == 0)
                break;
        int x = z % 3;//��һά����ת���ɶ�ά��
        int y = z / 3;//
        for(int i = 0; i < 4; i++) {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            int nz = newx + newy * 3;//����ά����ת����һά����
            if(newx >= 0&& newx < 3 && newy >= 0 && newy <3) {//��������� �˴����ж�����˼ ȷʵ�������ܱ�������ظ����ʵ�����
                node newnode;
                memcpy(&newnode,&head,sizeof(struct node));//����֮ǰ����Ϣ
                swap(newnode.state[z],newnode.state[nz]);//�ƶ�0��λ��
                newnode.dis++;
                if(memcmp(newnode.state,goal,sizeof(goal)) == 0)//ƥ��ɹ�
                    return newnode.dis;
                if(Cantor(newnode.state,9))//����
                    q.push(newnode);
            }
        }
    }
    return -1;
}
int main ()
{
    for(int i = 0; i < 9; i++) cin >> start[i];
    for(int i = 0; i < 9; i++) cin >> goal[i];
    int num = bfs();
    if(num != -1)
        cout << num << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
