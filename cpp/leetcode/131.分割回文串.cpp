#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  vector<vector<string>> res;
  vector<string> path;
  void backtracking(const string &s, int startIndex) {
    if (startIndex >= s.size()) {
      res.push_back(path);
      return;
    }

    for (int i = startIndex; i < s.size(); i++) {
      if (isPalindrome(s, startIndex, i)) {
        string str = s.substr(startIndex, i - startIndex + 1);
        path.push_back(str);
      }
    }
  }

  bool isPalindrome(const string &s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
      if (s[i] != s[j])
        return false;
    }
    return true;
  }
  vector<vector<string>> partition(string s) {
    res.clear();
    path.clear();
    backtracking(s, 0);
    return res;
  }
};
