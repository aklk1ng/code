#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string trans(string s, int n) {
    if (n == 0)
      return s;
    string res;
    for (int i = 0; i < n; i++) {
      if (s[i] <= 'z' && s[i] >= 'a')
        res += s[i] - 'a' + 'A';
      else if (s[i] <= 'Z' && s[i] >= 'A')
        res += s[i] - 'A' + 'a';
      else
        res += s[i];
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j < n && s[j] != ' ')
        j++;
      reverse(res.begin() + i, res.begin() + j);
      i = j;
    }
    return res;
  }
};

class Solution2 {
public:
  string trans(string s, int n) {
    if (n == 0)
      return s;
    string res;
    for (int i = 0; i < n; i++) {
      if (s[i] <= 'z' && s[i] >= 'a')
        res += s[i] - 'a' + 'A';
      else if (s[i] <= 'Z' && s[i] >= 'A')
        res += s[i] - 'A' + 'a';
      else
        res += s[i];
    }
    stack<string> st;
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j < n && res[j] != ' ')
        j++;
      st.push(res.substr(i, j - i));
      i = j;
    }
    if (s[n - 1] == ' ')
      res = " ";
    else
      res = "";
    while (!st.empty()) {
      res += st.top();
      st.pop();
      if (!st.empty())
        res += ' ';
    }
    return res;
  }
};
