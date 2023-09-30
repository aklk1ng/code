#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> w(n + 1);
  for (int i = 1; i <= n; i++) {
    w[i] = w[i - 1] + int(s[i - 1] == 'W');
  }
  int ans = INF;
  for (int i = k; i <= n; i++) {
    ans = min(ans, w[i] - w[i - k]);
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
