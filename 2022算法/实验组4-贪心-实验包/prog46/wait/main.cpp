#include<bits/stdc++.h>
using namespace std;
int fun(int a[],int n){
	int count=n;
	int sum=0;
	for(int i=0; i< n; i++) {
		sum=sum+a[i]*count;
		count--;
	}
	 return sum;
}
int main() {
    int a[1003]={0};
	for(int i=0;i<=9;i++){
		stringstream ss;
		ss<<i;
		string s;
		ss>>s;
	string st1="../test/wait"+s+".IN";
	string st2="../answer/wait"+s+".out";
	ifstream ifs1;
	ifstream ifs2;
	ifs1.open(st1.c_str());
	int k;
	ifs1>>k;
	for(int j=0; j < k; j++)
        ifs1>>a[j];
	ifs1.close();
    ifs2.open(st2.c_str());
    double answer;
	ifs2>>answer;
	ifs2.close();
    sort(a,a+k);
    int sum =  fun(a,k);
    cout << i << endl;
	cout <<answer*k<<' '<<sum<<endl;
}
	return 0;
}
