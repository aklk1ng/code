#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countWords(vector<string> &words1, vector<string> &words2) {
    unordered_map<string, int> freq1;
    unordered_map<string, int> freq2;
    int ans = 0;
    for (auto &word : words1)
      freq1[word]++;
    for (auto &word : words2)
      freq2[word]++;

    for (auto &[word, cnt] : freq1) {
      if (cnt == 1 && freq2[word] == 1)
        ans++;
    }
    return ans;
  }
};
