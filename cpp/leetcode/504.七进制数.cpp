#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string convertToBase7(int num) {
    if (num == 0)
      return "0";
    string flag = "";
    if (num < 0) {
      flag = "-";
      num = -num;
    }
    string res;
    while (num) {
      res += num % 7 + '0';
      num /= 7;
    }
    reverse(res.begin(), res.end());
    return flag + res;
  }
};

class Solution2 {
public:
  string convertToBase7(int num) {
    if (num == 0)
      return "0";
    string res;
    bool negative = num < 0;
    num = abs(num);
    while (num > 0) {
      res.push_back(num % 7 + '0');
      num /= 7;
    }
    if (negative)
      res.push_back('-');
    reverse(res.begin(), res.end());
    return res;
  }
};
