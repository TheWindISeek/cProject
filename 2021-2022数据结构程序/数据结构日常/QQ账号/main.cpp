#include <iostream>
#include <map>
using namespace std;

int main ()
{
    int n;
    char op;
    map<string,string> m;
    string id,password;
    cin >> n;
    while(n--){
        cin >> op >> id >> password;
        switch(op){
            case 'N'://������һ���˺�
                if(m.find(id)!= m.end())//����ҵ���
                    cout << "ERROR: Exist"<<endl;
                else//û���ҵ�
                {
                    m[id] = password;
                    cout << "New: OK"<<endl;
                }
                break;
            case 'L':
                if(m.find(id) != m.end())//����ҵ���
                {
                    if(m[id] == password)//����������ͬ
                        cout << "Login: OK"<<endl;
                    else//���벻ͬ
                        cout << "ERROR: Wrong PW"<<endl;
                }else//û�ҵ�
                    cout << "ERROR: Not Exist"<<endl;
                break;
        }
    }
    return 0��
}
