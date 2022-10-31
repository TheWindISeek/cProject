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
            case 'N'://新申请一个账号
                if(m.find(id)!= m.end())//如果找到了
                    cout << "ERROR: Exist"<<endl;
                else//没有找到
                {
                    m[id] = password;
                    cout << "New: OK"<<endl;
                }
                break;
            case 'L':
                if(m.find(id) != m.end())//如果找到了
                {
                    if(m[id] == password)//并且密码相同
                        cout << "Login: OK"<<endl;
                    else//密码不同
                        cout << "ERROR: Wrong PW"<<endl;
                }else//没找到
                    cout << "ERROR: Not Exist"<<endl;
                break;
        }
    }
    return 0；
}
