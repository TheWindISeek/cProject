#include <iostream>

using namespace std;
typedef struct link{
int data;
link* next;
}Link;
using LIST = Link*;
LIST merge (LIST A, LIST B){
LIST C;
Link* p,*q,*s;
p = A->next;
q = B -> next;
free(B);
C = A;
C -> next = NULL;
while(p && q){
    if(p -> data < q -> data){
        s = p;
        p = p ->next;
    }else {
    s = q;
    q = q-> next;
    }
    s ->next = C ->next;
    C ->next = NULL;
}
if(p == NULL){
    p = q;
}
while(p){
    s = p;
    p = p->next;
    s -> next = C ->next;
    C -> next = NULL;
}
return C;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
