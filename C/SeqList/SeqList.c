//顺序表
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SListDataType;
typedef struct SeqList
{
    SListDataType* a;
    int size;
    int capacity;
}SL;
void SeqListPrint(SL* ps)
{
    int i;
    for(i=0;i<ps->size;i++){
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}
void SeqListInit(SL* ps)
{
    ps->a=NULL;
    ps->capacity=0;
    ps->size=0;
}
void SeqListDestory(SL* ps)
{
    free(ps->a);
    ps->a=NULL;
    ps->capacity=0;
    ps->size=0;
}
void SeqListCheckcapacity(SL* ps)
{
    if(ps->size==ps->capacity){
        int newcapacity=ps->capacity==0?4:ps->capacity*2;
        SListDataType* tmp=(SListDataType*)realloc(ps->a, newcapacity*sizeof(SListDataType));
        if(tmp==NULL){
            printf("realloc failed!\n");
            exit(-1);
        }
        ps->a=tmp;
        ps->capacity=newcapacity;
    }
}
void SeqListInsert(SL* ps, int pos, SListDataType x)
{
    assert(pos>=0&&pos<=ps->size);
    SeqListCheckcapacity(ps);
    int end=ps->size;
    while(end>pos){
        ps->a[end]=ps->a[end-1];
        end--;
    }
    ps->a[pos]=x;
    ps->size++;
}
void SeqListErase(SL* ps, int pos)
{
    assert(pos>=0&&pos<=ps->size-1);
    int begin=pos;
    while(begin<=ps->size-1){
        ps->a[begin]=ps->a[begin+1];
        begin++;
    }
    ps->size--;
}
int SeqListFind(const SL* ps, SListDataType x)
{
    int i;
    for(i=0;i<ps->size;i++){
        if(ps->a[i]==x){
            return i;
        }
    }
    return -1;
}
void test1()
{
    SL s1;
    SeqListInit(&s1);
    SeqListInsert(&s1,0,1);
    SeqListInsert(&s1,1,2);
    SeqListInsert(&s1,2,3);
    SeqListInsert(&s1,3,4);
    printf("%d\n", SeqListFind(&s1,3));
    SeqListErase(&s1, 0);
    SeqListPrint(&s1);
}
int main()
{
    test1();
    return 0;
}