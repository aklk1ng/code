#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubArray(string s) {
    int n = s.size();
    int ans = 0;
    unordered_map<char, int> hash;
    int l = 0;
    for (int r = 0; r < n; r++) {
      hash[s[r]]++;
      while (hash[s[r]] > 1) {
        hash[s[l]]--;
        l++;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
