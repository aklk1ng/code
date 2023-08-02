#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool detectCapitalUse(string word) {
    if (word.size() >= 2 && isupper(word[1]) && islower(word[0]))
      return false;

    for (int i = 2; i < word.size(); i++)
      if (islower(word[i]) ^ islower(word[1]))
        return false;

    return true;
  }
};
