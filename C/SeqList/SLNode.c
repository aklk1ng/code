//单向不循环链表
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqListNode
{
    SLDataType data;
    struct SeqListNode* next;
}SLNode;
void SListPrint(SLNode* phead)
{
    SLNode* cur=phead;
    while(cur){
        printf("%d->",cur->data);
        cur=cur->next;
    }
    printf("NULL\n");
}
SLNode* CreateNewNode(SLDataType x)
{
    SLNode* newnode=(SLNode*)malloc(sizeof(SLNode));
    if(newnode==NULL){
        printf("malloc failed!\n");
        exit(-1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void SListInsert(SLNode* pos, SLDataType x)
{
    assert(pos);
    SLNode* newnode=CreateNewNode(x);
    newnode->next=pos->next;
    pos->next=newnode;
}
SLNode* SListFind(SLNode* phead, SLDataType x)
{
    SLNode* cur=phead;
    while(cur){
        if(cur->data==x){
            return cur;
        }
        else{
            cur=cur->next;
        }
    }
    return NULL;
}
void SListPushFront(SLNode** pphead, SLDataType x)
{
    SLNode* newnode=CreateNewNode(x);
    newnode->next=*pphead;
    *pphead=newnode;
}
void SListPushBack(SLNode** pphead, SLDataType x)
{
    SLNode* newnode=CreateNewNode(x);
    if(*pphead==NULL){
        *pphead=newnode;
    }
    else{
        SLNode* tail=*pphead;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=newnode;
    }
}
void SListPopFront(SLNode** pphead)
{
    assert(*pphead!=NULL);
    SLNode* cur=*pphead;
    *pphead=(*pphead)->next;
    free(cur);
}
void SListErase(SLNode** pphead, SLNode* pos)
{
    SLNode* tail=*pphead;
    if(*pphead==pos){
        *pphead=pos->next;
        free(pos);
    }
    else{
        while(tail->next!=pos){
            tail=tail->next;
        }
        tail->next=pos->next;
        free(pos);
    }
}
void SListDestory(SLNode** pphead)
{
    assert(pphead);
    SLNode* cur=*pphead;
    while(cur){
        SLNode* next=cur->next;
        free(cur);
        cur=next;
    }
    *pphead=NULL;
}
void test1()
{
    SLNode* n1=NULL;
    SListPushFront(&n1,1);
    SListPushBack(&n1,5);
    SLNode* pos=SListFind(n1, 5);
    SListInsert(pos,6);
    SListErase(&n1,pos);
    SListPopFront(&n1);
    SListPrint(n1);
    SListDestory(&n1);
}
int main()
{
    test1();
    return 0;
}
