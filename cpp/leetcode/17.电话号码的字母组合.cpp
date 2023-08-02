#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  const string lettermap[10] = {
      "",     // 0
      "",     // 1
      "abc",  // 2
      "def",  // 3
      "ghi",  // 4
      "jkl",  // 5
      "mno",  // 6
      "pqrs", // 7
      "tuv",  // 8
      "wxyz", // 9
  };

public:
  vector<string> res;
  string s;
  void backtracking(string &digits, int index) {
    if (index == digits.size()) {
      res.push_back(s);
      return;
    }

    int digit = digits[index] - '0';
    string letters = lettermap[digit];
    for (int i = 0; i < letters.size(); i++) {
      s.push_back(letters[i]);
      backtracking(digits, index + 1);
      s.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    res.clear();
    s.clear();
    if (digits.size() == 0)
      return res;
    backtracking(digits, 0);
    return res;
  }
};
