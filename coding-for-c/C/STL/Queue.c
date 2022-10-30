//链式队列,非循环
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int QDataType;
typedef struct QueueNode
{
    QDataType data;
    struct QueueNode* next;
}QueueNode;
typedef struct Queue
{
    QueueNode* head;
    QueueNode* tail;
}Queue;
void QueueInit(Queue* ps)
{
    assert(ps);
    ps->head=NULL;
    ps->tail=NULL;
}
void QueueDestroy(Queue* ps)
{
    assert(ps);
    QueueNode* cur=ps->head;
    while(cur!=NULL) {
        QueueNode* next=cur->next;
        free(cur);
        cur=next;
    }
    ps->tail=NULL;
    ps->head=NULL;
}
void QueuePush(Queue* ps, QDataType x)
{
    assert(ps);
    QueueNode* newnode=(QueueNode*)malloc(sizeof(QueueNode));
    if(newnode==NULL) {
        printf("malloc failed!\n");
        exit(-1);
    }
    newnode->data=x;
    newnode->next=NULL;
    if(ps->head==NULL) {
        ps->head=ps->tail=newnode;
    }
    else {
        ps->tail->next=newnode;
        ps->tail=newnode;
    }
}
//删除队头的数据
void QueuePop(Queue* ps)
{
    assert(ps);
    assert(ps->head!=NULL);
    QueueNode* next=ps->head->next;
    free(ps->head);
    ps->head=next;
    //如果队列中只有一个元素，删除后还要把队尾置空
    if(ps->head==NULL) {
        ps->tail=NULL;
    }
}
//获取数据
QDataType QueueFront(Queue* ps)
{
    assert(ps);
    assert(ps->head!=NULL);
    return ps->head->data;
}
QDataType QueueBack(Queue* ps)
{
    assert(ps);
    assert(ps->head!=NULL);
    return ps->tail->data;
}

int QueueSize(Queue* ps)
{
    assert(ps);
    QueueNode* cur=ps->head;
    int n=0;
    while(cur) {
        n++;
        cur=cur->next;
    }
    return n;
}
void test()
{
    Queue ps;
    QueueInit(&ps);
    QueuePush(&ps, 0);
    QueuePush(&ps, 1);
    QueuePush(&ps, 2);
    QueuePush(&ps, 3);
    QueuePush(&ps, 4);
    QueuePush(&ps, 5);
    printf("%d\n",QueueFront(&ps));
    printf("%d\n",QueueBack(&ps));
    printf("%d\n",QueueSize(&ps));
    QueuePop(&ps);
    printf("%d\n",QueueSize(&ps));
    QueueDestroy(&ps);
}
int main()
{
    test();
    return 0;
}
