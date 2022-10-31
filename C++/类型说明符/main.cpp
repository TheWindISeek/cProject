#include <iostream>

using namespace std;

int main()
{
    //typedef说明符
    //下面两个定义并不相同，应当看到的是 * 是前面定义的东西，不应该拆开看待
    typedef char * pstring;
    const pstring cstr_ = 0;//指向char的常量指针
    //亦或者说，这个和char * const cstr_;相同
       const char * cstr=0;//指针指向的char必须是常量||指向const char的指针
const pstring *ps=nullptr;

//using说明符,定义类型的别名，目前我还不会使用

//auto类型说明符
//相关特性：会忽略顶层const，但不会忽略底层const，如果想让顶层const保留，可自加，给程序员最大的自由，不忽略底层const是因为难以直接说明（现阶段理解2021）。
auto i=cstr;
int ci;
const int m=0;
auto &g=ci;
//同样的，auto仍然遵循引用的相关规则，不加const无法绑定到字面值上去，即下面这句会报错\
auto &h=42;
const auto &j=42;
//还需要注意一点就是auto后面所有的类型会一致，如果不一致，就像下面会报错，原因是const int != int 学完const应该意识到这一点。换言之，类型和const也相关\
auto &n=i,*p2=&m;


//（Declared Type）也就是decltype
const int y=0,&q=y;
decltype (y) x=0;
decltype (q) cq=y;
//以下语句错误，原因是decltype并不会将引用看为其引用类型的类型，而是看成引用，也就需要赋初值。\
decltype (q) vc;
//还应该认识到的decltype的结果可以是引用类型，并最终采用的数据类型是括号里表示式最终的值，这个值如果是引用类型，那么后面的也会是引用类型
int num = 13,*pint =&num,&r = num;
decltype (r+0) b;//b为int类型，只判断r应该是引用类型，但是如果加上了0，就变为了int 类型，和自动类型转换是一样的
decltype (*pint) c=num;;//对指针的解引用，对应的类型并不是指针解引用所对应的类型，而是对应类型的引用，故此处会报错，需要初始化。（initialized）
//还有需要注意的一点是如果在括号里面加入了（），则会得到引用类型，此时需要初始化，双层括号始终是引用。
/*
decltype ((i)) d;//错误
decltype (i) b;//正确
*/


    cout << "I LOVE C++!" << endl;
    return 0;
}
