#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, s, r;
  cin >> n >> s >> r;
  int mx = s - r;
  vector<int> ans(n, 1);
  ans[0] = mx;
  int cur = mx + n - 1;
  for (int i = 1; i < n; i++) {
    if (cur < s) {
      int diff = s - cur;
      int tmp = ans[i];
      ans[i] = min(mx, diff + ans[i]);
      cur += ans[i] - tmp;
    }
  }
  for (auto &i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
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
