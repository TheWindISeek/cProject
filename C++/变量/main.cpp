#include <iostream>

using namespace std;

int main()
{
    cout.setf(ios_base::fixed,ios_base::floatfield);
    float tub = 10.0 /3.0;
    double mint = 10.0 /3.0;
    const float millon =1.0e6;

    cout<<"tub = "<<tub<<",a millon tubs = "<<millon *tub<<",\nand ten millon tubs ="<<10*millon<<endl<<"mint ="<<mint <<"and a millon mints = "<<millon*mint<<endl;
    return 0;
}
