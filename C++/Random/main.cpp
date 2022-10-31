#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
//Ñ¡¿Î×¨ÓÃ
int main()
{
srand(time(NULL));

    cout << rand()%3 << endl;
    return 0;
}
