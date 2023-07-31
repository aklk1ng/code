#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  stack<char> st;
  for (auto x : s) {
    if (!st.empty() && st.top() == x)
      st.pop();
    else
      st.push(x);
  }
  if (st.empty())
    cout << 0 << endl;

  int n = st.size();
  vector<char> res;
  for (int i = n - 1; i >= 0; i--) {
    res[i] = st.top();
    st.pop();
  }

  for (int i = 0; i < n; i++)
    cout << res[i];
  return 0;
};
