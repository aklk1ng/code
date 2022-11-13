//双向循环链表
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTNDataType;
typedef struct ListNode
{
    LTNDataType data;
    struct ListNode* prev;
    struct ListNode* next;
}LNode;
LNode* CreateNode(LTNDataType x)
{
    LNode* newnode=(LNode*)malloc(sizeof(LNode));
    if(newnode==NULL) {
        printf("malloc failed!\n");
        exit(-1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
LNode* ListInit()
{
    LNode* phead=(LNode*)malloc(sizeof(LNode));
    if(phead==NULL) {
        printf("malloc failed!\n");
        exit(-1);
    }
    phead->prev=phead;
    phead->next=phead;
    return phead;
}
void ListPrint(LNode* phead)
{
    assert(phead);
    LNode* cur=phead->next;
    while(cur!=phead) {
        printf("%d ", cur->data);
        cur=cur->next;
    }
    printf("\n");
}
LNode* ListFind(LNode* phead, LTNDataType x)
{
    assert(phead);
    LNode* cur=phead->next;
    while(cur!=phead) {
        if(cur->data==x) {
            return cur;
        }
        else {
            cur=cur->next;
        }
    }
    return NULL;
}
void ListDestroy(LNode* phead)
{
    assert(phead);
    LNode* cur=phead->next;
    while(cur!=phead) {
        LNode* next=cur->next;
        free(cur);
        cur=next;
    }
    free(phead);
}
void ListInsert(LNode* pos, LTNDataType x)
{
    assert(pos);
    LNode* newnode=CreateNode(x);
    LNode* posprev=pos->prev;
    posprev->next=newnode;
    newnode->prev=posprev;
    newnode->next=pos;
    pos->prev=newnode;
}
void ListErase(LNode* pos)
{
    assert(pos);
    LNode* posprev=pos->prev;
    LNode* posnext=pos->next;
    posprev->next=posnext;
    posnext->prev=posprev;
    free(pos);
    pos=NULL;
}
void ListPushFront(LNode* phead, LTNDataType x)
{
    assert(phead);
    ListInsert(phead->next, x);
}
void ListPushBack(LNode* phead, LTNDataType x)
{
    assert(phead);
    ListInsert(phead, x);
}
void test()
{
    LNode* plist=ListInit();
    ListPushFront(plist,1);
    ListPushBack(plist,2);
    ListPushBack(plist,3);
    ListPushBack(plist,4);
    ListPushBack(plist,5);
    ListPrint(plist);
    LNode* pos=ListFind(plist,3);
    ListErase(pos);
    ListPrint(plist);
    ListDestroy(plist);
    plist=NULL;
}
int main()
{
    test();
    return 0;
}
