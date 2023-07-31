#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int solve(string s) { return operation(s, 0)[0]; }

  vector<int> operation(string s, int idx) {
    stack<int> st;
    int num = 0;
    char op = '+';
    int i;
    for (i = idx; i < s.length(); i++) {
      // for number
      if (isdigit(s[i])) {
        num = num * 10 + s[i] - '0';
        if (i != s.length() - 1)
          continue;
      }

      // begin recursion
      if (s[i] == '(') {
        vector<int> res = operation(s, i + 1);
        num = res[0];
        i = res[1];
        if (i != s.length() - 1)
          continue;
      }

      switch (op) {
      case '+':
        st.push(num);
        break;
      case '-':
        st.push(-num);
        break;
      case '*':
        int tmp = st.top();
        st.pop();
        st.push(tmp * num);
        break;
      }
      num = 0;
      if (s[i] == ')')
        break;
      else
        op = s[i];
    }

    int sum = 0;
    while (!st.empty()) {
      sum += st.top();
      st.pop();
    }

    return vector<int>{sum, i};
  }
};
