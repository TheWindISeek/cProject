#include "2jjalloc.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
static void (* __malloc_alloc_oom_handler)();
static void (* set_malloc_handler(void (*f)()))()
{
    void (* old)() = __malloc_alloc_oom_handler;
    __malloc_alloc_oom_handler = f;
    return old;
}

int main()
{
    set_malloc_handler(0);
    sort();
    return 0;
}
