#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node* List;
List add (List head , int data){
    if (head ==NULL ){
        head = (List)malloc (sizeof(struct Node ) );
        head -> next = NULL;
        head -> data = data;
        return head;
    }
    List p = head,pt = (List)malloc (sizeof(struct Node ) );
     pt -> next = NULL;
        pt -> data = data;
    while(p->next != NULL){
        p = p -> next;
    }
    p -> next = pt;
    return head;
}
void print(List head ){
    if(head == NULL){
        printf("NULL");
        return;
    }
    List p = head;
    while(p != NULL ){
        printf("%d",p->data);
        p = p -> next;
        if(p != NULL)
        printf(" ");
    }
}

List both (List first ,List second){

    List q = (List)malloc(sizeof (struct Node));
    q->next = NULL;
    List head = q;
    for(List p1 = first, p2 = second; p1 != NULL  && p2 != NULL; )
    {
        if (p1->data > p2-> data){
            p2 = p2 ->next;

        }else if (p1 -> data == p2-> data){
            List  p = (List)malloc(sizeof (struct Node));
            p -> next = NULL;
            p-> data = p1->data;
            q -> next = p;
            q = q ->next;
            p2 = p2 ->next;
            p1 = p1 -> next;
        }else{
            p1 = p1 -> next;
        }
    }
    return head->next;
}
int main (){

    int data;
    List s1,s2,s3;

    s1 = s2 = s3 =NULL;
    while(1){
        scanf("%d",&data);
        if(data < 0){
            break;
        }
        s1 = add(s1,data);
    }
     while(1){
        scanf("%d",&data);
        if(data < 0){
            break;
        }
        s2 = add(s2,data);
    }
s3 = both(s1,s2,s3);
    print(s3);
return 0;

}
