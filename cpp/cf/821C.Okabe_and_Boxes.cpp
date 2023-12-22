#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  stack<int> st;
  int cur = 1, ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    string op;
    cin >> op;
    if (op == "add") {
      int x;
      cin >> x;
      st.push(x);
    } else if (op == "remove") {
      if (!st.empty()) {
        if (st.top() == cur) {
          st.pop();
        } else {
          ans++;
          while (!st.empty()) {
            st.pop();
          }
        }
      }
      cur++;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
