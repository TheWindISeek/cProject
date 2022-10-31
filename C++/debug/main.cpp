#include <iostream>

using namespace std;

class mine
{
private :

    int i;
    int k;

public :

    void heart ()
    {
        cout<<i<<endl;
    }

};
int main()
{
    mine k ;
    k.heart();
    cout << "Hello world!" << endl;
    return 0;
}
