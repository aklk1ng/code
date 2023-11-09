#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (n % 2) {
    cout << "No\n";
    return;
  }

  stack<char> st;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      st.push(s[i]);
    } else if (s[i] == ')' && !st.empty() && st.top() == '(') {
      st.pop();
    } else {
      st.push(s[i]);
    }
  }

  if (st.empty()) {
    cout << "Yes\n";
  } else if ((int)st.size() == 2) {
    int l = st.top();
    st.pop();
    int r = st.top();
    st.pop();
    if (l == '(' && r == ')') {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  } else {
    cout << "No\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
