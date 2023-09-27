#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  string s;
  cin >> s;
  s = " " + s;
  int n = s.size() - 1;
  vector<int> pre(n + 2), last(n + 2);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'B') {
      pre[i] = ans;
    } else {
      ans += s[i] == 'A';
      pre[i] = pre[i - 1];
    }
  }
  ans = 0;
  for (int i = n; i >= 1; i--) {
    if (s[i] == 'B') {
      last[i] = ans;
    } else {
      ans += s[i] == 'A';
      last[i] = last[i + 1];
    }
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'B') {
      ans = max(ans, max(pre[i] + last[i + 1], pre[i - 1] + last[i]));
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
