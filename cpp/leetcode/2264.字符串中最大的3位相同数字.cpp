#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string largestGoodInteger(string num) {
    string res;
    for (int i = 0; i < num.size() - 2; i++) {
      if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
        res = max(res, num.substr(i, 3));
    }
    return res;
  }
};
