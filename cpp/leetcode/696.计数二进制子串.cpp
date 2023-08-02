#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countBinarySubStrings(string s) {
    int ptr = 0, n = s.size(), last = 0, ans = 0;
    while (ptr < n) {
      char ch = s[ptr];
      int count = 0;
      while (ptr < n && s[ptr] == ch) {
        ptr++;
        count++;
      }

      ans += min(count, last);
      last = count;
    }
    return ans;
  }
};
