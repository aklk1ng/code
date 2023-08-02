#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string reversePrefix(string word, char ch) {
    for (int i = 0; i < word.size(); i++) {
      if (word[i] == ch) {
        int j = 0;
        while (j < i) {
          swap(word[i], word[j]);
          j++;
          i--;
        }
        return word;
      }
    }
    return word;
  }
};

class Solution2 {
public:
  string reversePrefix(string word, char ch) {
    int idx = word.find(ch);
    if (idx != string::npos)
      reverse(word.begin(), word.begin() + idx + 1);
    return word;
  }
};
