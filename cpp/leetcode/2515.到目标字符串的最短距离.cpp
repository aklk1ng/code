#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int closetTarget(vector<string> &words, string target, int startIndex) {
    int n = words.size();
    int ans = n;
    for (int i = 0; i < n; i++) {
      if (words[i] == target) {
        ans = min(ans, min(i - startIndex, n - abs(i - startIndex)));
      }
    }
    return (ans < n ? ans : -1);
  }
};
