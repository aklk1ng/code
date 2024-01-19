#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  stack<int> st;
  b[0] = INF;
  st.push(0);
  for (int i = 1; i <= n; i++) {
    b[i] = 1;
    while (st.size() && a[i] > a[st.top()]) {
      b[i] = max(b[i], b[st.top()] + 1);
      st.pop();
    }
    st.push(i);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] < INF) {
      ans = max(ans, b[i]);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (false) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
