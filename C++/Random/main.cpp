#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
//ѡ��ר��
int main()
{
srand(time(NULL));

    cout << rand()%3 << endl;
    return 0;
}
