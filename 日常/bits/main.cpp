#include <cstdio>
#include <iostream>
#include <windows.h>
using namespace std;
/*
如果是最大的int 0x7fffffff
返回1否则返回0
*/
int isTmax(int x) {
    int y = (x + 1) ^ x;
    //printf("%x\n", y);
    int z = !((x + 1) & y);
    //printf("%x\n", z);
    return !(~(y ^ z));
}
/*
输入数x的奇数位都是1 则返回1 否则返回0
0xffffffff = 1
0xfffffffd = 0
0xaaaaaaaa = 1
*/
int allOddBits(int x) {
    int aa = 0xAA;

    /*
    //每八位进行判断 先用aa防止偶数位的干扰 再用xor判断相等
    int x0 = (x & aa) ^ aa;
    int x1 = ((x >> 8) & aa) ^ aa;
    int x2 = ((x >> 16) & aa) ^ aa;
    int x3 = ((x >> 24) & aa) ^ aa;
    return !(x0 | x1 | x2 | x3);*/

    /*
    //为上面式子的化简
    int x1 = x >> 8;
    int x2 = x >> 16;
    int x3 = x >> 24;
    return !(aa & ~(x & x1 & x2 & x3));*/

    //构造 0xaaaa_aaaa 直接进行判断
    int a_16 = (aa << 8) | aa;
    int a_32 = (a_16 << 16) | a_16;
    return !((a_32 & x) ^ a_32);

}
/*
ops = 5
*/
int negate(int x) {
    return ~x + 1;
}

/*
return 1 if 0x30 <= x <= 0x39
ops = 15
*/
int isAsciiDigit(int x) {
    int y = x + ~0x30 + 1;
    int z = 0x39 + ~x + 1;
    y = y >> 31;
    z = z >> 31;
    return !(y | z);
}
/*
same as x ? y : z
ops = 16
*/
int coditional(int x, int y, int z) {
    x = ~!!x + 1;
    return (x & y) | (~x & z);
}
/*
if x <= y return 1 else return 0
    ops = 24
    using subtraction will cause overflow then answer is wrong
*/
int isLessOrEqual(int x, int y) {
    int z = y + ~x + 1;
    printf("%x\n", z);
    return !(z >> 31);
}
/*
implement the ! operator
logicalNeg(3) = 0
logicalNeg(0) = 1
ops = 12
*/
int logicalNeg(int x) {
    int y = x | ((~x + 1) ^ x) ;
    y >>= 31;
    return y + 1;
}
/*
return the minimun number of the bits required to represent x in 2
*/
int howManyBits(int x) {
    return 0;
}
/*
return bit-level equivalent of expression 2*f for floating point argument f
*/
unsigned floatScale2(unsigned uf) {
    return 2;
}
/*
return bit-level equivalent of expression(int)f for floating point argument f
*/
int floatFloat2Int(unsigned uf) {
    return 2;
}
/*
return bit-level equivalent of the expression 2.0^x
*/
unsigned floatPower2(int x) {
    return 2;
}
int main()
{
    /*cout << allOddBits(-1) << endl;
    cout << allOddBits(INT_MAX) << endl;
    cout << allOddBits(0xfffffffd) << endl;
    cout << allOddBits(0xaaaaaaaa) << endl;*/
    /*cout << isAsciiDigit('0') << endl;
    cout << isAsciiDigit('a') << endl;
    cout << isAsciiDigit('9') << endl;
    cout << isAsciiDigit('5') << endl;*/

   /* cout << coditional(2, 3, 6) << endl;
    cout << coditional(0, 3, 6) << endl;

    cout << isLessOrEqual(INT_MAX, INT_MIN) << endl;
    cout << isLessOrEqual(INT_MIN, INT_MAX) << endl;
    cout << isLessOrEqual(0, 1) << endl;
    cout << isLessOrEqual(-4, 9) << endl;

    cout << logicalNeg(0) << endl;
    cout << logicalNeg(2) << endl;
    cout << logicalNeg(INT_MIN) << endl;*/
    unsigned char i = 134;
    unsigned char j = 246;
    unsigned char x = i - j;
    printf("%d %u %d %d", x, x, sizeof(char), sizeof(unsigned char));

    return 0;
}
