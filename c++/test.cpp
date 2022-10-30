//nullptr
/* #include <iostream> */
/* using namespace std; */
/* void func(char* p) */
/* { */
/*     cout<<"void functin char *p"<<endl; */
/* } */
/* void func(int p) */
/* { */
/*     cout<<"void function int p"<<endl; */
/* } */
/* int main(int argc, char *argv[]) */
/* { */
/*     int* ptr1 = nullptr; */
/*     char* ptr2 = nullptr; */
/*     double* ptr3 = nullptr; */
/*     void* ptr4 = nullptr; */
/*     int* ptr5 = (int*)ptr4; */
/*     func(10); */
/*     func(nullptr); */
/*     return 0; */
/* } */


//decltype--声明类型,自动推导
#include <iostream>
using namespace std;
void test(int arr[], int len)
{
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-i; j++) {
            if (arr[j]  > arr[j+1]) {
                int tmp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
int main (int argc, char *argv[])
{
    int arr[]={1,4,0,4,6,1,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<len<<endl;
    for (int i=0 ; i< len; i++){
        cout<<arr[i]<<" ";
    }
    test(arr,len);
    cout<<"\n";
    for (int i=0 ; i< len; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
