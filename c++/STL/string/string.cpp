#include <iostream>
#include <string>
#include <system_error>
using namespace std;

void test1() {
    string s1;
    const char *str = "hello";
    string s2(str);
    cout << s2 << endl;
    string s3(s2);
    cout << s3 << endl;
    string s4(10, 'a');
    cout << s4 << endl;
}

// string assignment operation
void test2() {
    // string& operator=(const char *s)
    string str1;
    str1 = "hello";
    cout << str1 << endl;

    // string& operator=(const char &s)
    string str2;
    str2 = str1;
    cout << str2 << endl;

    // string& operator=(char c)
    string str3;
    str3 = 'a';
    cout << str3 << endl;

    // string& assign(const char *s)
    string str4;
    str4.assign("hello cpp");
    cout << str4 << endl;

    // string& assign(const char *s, int n)
    string str5;
    str5.assign("hello world cpp", 10);
    cout << str5 << endl;

    // string& assign(const string &s)
    string str6;
    str6.assign(str1);
    cout << str6 << endl;

    // string& assign(int n, char c)
    string str7;
    str7.assign(4, 'c');
    cout << str7 << endl;
}

// string append operator
void test3() {
    // string& operator+=(const char *str)
    string str1 = "a";
    str1 += "aa";
    cout << str1 << endl;

    // string& operator+=(const char c)
    string str2 = "b";
    str2 += "b";
    cout << str2 << endl;

    // string& operator+=(const char& str)
    string str3 = "Haaaaa!";
    str3 += str2;
    cout << str3 << endl;

    // string& append(const char *s)
    string str4 = "4";
    str4.append("44");
    cout << str4 << endl;

    // string& append(const char *s, int n)
    string str5 = "5";
    str5.append("55", 1);
    cout << str5 << endl;

    // string& append(const string *s)
    string str6 = "6";
    str6.append(str5);
    cout << str6 << endl;

    // string& append(const string *s, int pos, int n)
    string str7 = "7";
    str7.append(str6, 0, 2);
    cout << str7 << endl;
}

// string find and replace operator
void test4() {
    // the find function find the string from left to right
    string str1 = "abc";
    int pos = str1.find("de");
    /* int pos = str1.find("ab"); */
    cout << pos << endl;

    // the rfind function find the string from right to left
    pos = str1.rfind("de");
    cout << pos << endl;

    // but the find function and the rfind function
    // will have the same result

    // replace
    string str2 = "defgh";
    str2.replace(1, 3, "1111");
    cout << str2 << endl;
}

// string compare
void test5() {
    string str1 = "a";
    string str2 = "b";
    int pos = str1.compare(str2);
    cout << pos << endl;
}

// string read and write
void test6() {
    string str1 = "abcd";
    cout << str1[1] << endl;
    cout << str1.at(2) << endl;
}

// string insert and delete
void test7() {
    string str1 = "abcde";
    str1.insert(5, "f");
    cout << str1 << endl;

    str1.erase(5, 1);
    cout << str1 << endl;
}

// get a substring of a string
void test8() {
    string str = "abcdef@gmail.com";
    int pos = str.rfind("@");
    cout << pos << endl;
    string substr = str.substr(0, pos);
    cout << substr << endl;
}
int main(int argc, char *argv[]) {
    /* test1(); */
    /* test2(); */
    /* test3(); */
    /* test4(); */
    /* test5(); */
    /* test6(); */
    /* test7(); */
    test8();
    return 0;
}
