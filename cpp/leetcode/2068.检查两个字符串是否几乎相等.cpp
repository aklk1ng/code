#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool checkAlmostEquivalment(string word1, string word2) {
    int hash1[26] = {0};
    int hash2[26] = {0};

    for (char s : word1)
      hash1[s - 'a']++;
    for (char s : word2)
      hash2[s - 'a']++;

    for (int i = 0; i < 26; i++)
      if (abs(hash1[i] - hash2[i]) > 3)
        return false;
    return true;
  }
};
