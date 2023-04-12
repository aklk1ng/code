#include <iostream>
using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int res[26] = {0};
    if (ransomNote.size() > magazine.size()) {
      return false;
    }
    for (int i = 0; i < magazine.size(); i++) {
      res[magazine[i] - 'a']++;
    }
    for (int j = 0; j < ransomNote.size(); j++) {
      res[ransomNote[j] - 'a']--;
      if (res[ransomNote[j] - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};
