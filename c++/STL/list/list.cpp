#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void Print(const list<int>&l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
       cout << *it << " "; 
    }
    cout << endl;
}
void test()
{
    list<int>l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    Print(l);

    list<int>l1(l);
    Print(l1);

    list<int>l2(10 ,6);
    Print(l2);
}

// list assign and swap operator
void test1()
{
    list<int>l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    list<int>l1;
    l1.assign(l.begin(), l.end());
    Print(l1);

    list<int>l2;
    l2.assign(10, 6);
    Print(l2);

    l1.swap(l2);
    Print(l1);
    Print(l2);
}

// list insert and erase
void test2()
{
    list<int>l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(4);
    l.push_back(4);
    l.push_back(5);
    Print(l);
    l.pop_back();
    l.pop_front();
    Print(l);
    l.insert(l.end(), 6);
    l.erase(l.begin());
    Print(l);
    l.remove(4);
    Print(l);
}

// list reverse and sort
bool myCompare(int v1, int v2)
{
    return v1 > v2;
}
void test3()
{
    list<int>l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    Print(l);
    l.reverse();
    Print(l);
    l.push_back(5);
    l.push_back(3);
    // default is ascending
    l.sort();
    Print(l);
    // the descending
    l.sort(myCompare);
    Print(l);
}
int main (int argc, char *argv[])
{
    /* test(); */    
    /* test1(); */
    /* test2(); */
    test3();
    return 0;
}
