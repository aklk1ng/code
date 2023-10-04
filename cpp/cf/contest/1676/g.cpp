#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 4e3 + 5;

void solve() {
  int n;
  cin >> n;
  int a;
  vector<vector<int>> fa(n + 1);
  for (int i = 2; i <= n; i++) {
    cin >> a;
    fa[a].push_back(i);
  }
  string s;
  cin >> s;
  int ans = 0;
  function<int(int)> dp = [&](int x) {
    int bal = (s[x - 1] == 'B') ? -1 : 1;
    if (fa[x].empty()) {
      return bal;
    }
    for (int &i : fa[x]) {
      bal += dp(i);
    }
    if (bal == 0) {
      ans++;
    }
    return bal;
  };
  dp(1);
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
