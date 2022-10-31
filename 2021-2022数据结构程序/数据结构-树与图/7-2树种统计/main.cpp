//用map应该就行了
/*
输入首先给出正整数N
随后N行，每行给出卫星观测到的一棵树的种类名称。
种类名称由不超过30个英文字母和空格组成（大小写不区分）
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;
    getchar();
    map<string,int> m;
    for(int i = 0; i < n;++i){
        getline(cin,s);
        m[s]++;
    }
    int flag = 1;
    for(auto i = m.begin(); i != m.end();++i){
        if(flag)
        {
            cout<<i->first;
            printf(" %.4f%%",(float)i->second*100/(float)n);
            flag = 0;
        }else{
            cout << endl;
            cout<<i->first;
            printf(" %.4f%%",(float)i->second*100/(float)n);
        }
    }
    return 0;
}
/*
Ash 13.7931%
Aspen 3.4483%
Basswood 3.4483%
Beech 3.4483%
Black Walnut 3.4483%
Cherry 3.4483%
Cottonwood 3.4483%
Cypress 3.4483%
Gum 3.4483%
Hackberry 3.4483%
Hard Maple 3.4483%
Hickory 3.4483%
Pecan 3.4483%
Poplan 3.4483%
Red Alder 3.4483%
Red Elm 3.4483%
Red Oak 6.8966%
Sassafras 3.4483%
Soft Maple 3.4483%
Sycamore 3.4483%
White Oak 10.3448%
Willow 3.4483%
Yellow Birch 3.4483%
*/
