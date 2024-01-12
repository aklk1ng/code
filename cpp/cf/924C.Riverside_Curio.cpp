#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> m(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> m[i];
  }
  for (int i = n - 1, cur = 0; i >= 0; i--) {
    cur = max(0, cur - 1);
    cur = max(cur, m[i] + 1);
    t[i] = cur;
  }

  ll ans = 0;
  for (int i = 0, cur = 0; i < n; i++) {
    cur = max(cur, t[i]);
    ans += cur;
  }
  for (int i = 0; i < n; i++) {
    ans -= m[i] + 1;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
