#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int minDeletions(string s) {
    int res = 0;
    int freq[26] = {0};
    for (auto &i : s)
      freq[i - 'a']++;

    set<int> set;
    for (int i = 0; i < 26; i++) {
      if (set.find(freq[i]) == set.end()) {
        set.insert(freq[i]);
        continue;
      }
      while (set.find(freq[i]) != set.end() && freq[i] > 0) {
        res++;
        freq[i]--;
      }
      set.insert(freq[i]);
    }
    return res;
  }
};
