#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n + 1);
  int mi = d, pos = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] - a[i - 1] - 1 < mi) {
      mi = a[i] - a[i - 1] - 1;
      pos = i;
    }
  }
  vector<int> v;
  for (int i = 0; i <= n; i++) {
    if (i != pos) {
      v.push_back(a[i]);
    }
  }

  auto cnt = [&]() {
    int mx = 0, mn = INF;
    for (int i = 1; i < n; i++) {
      mx = max(mx, v[i] - v[i - 1] - 1);
      mn = min(mn, v[i] - v[i - 1] - 1);
    }
    return min(mn, max(d - v.back() - 1, (mx - 1) / 2));
  };
  int ans = cnt();
  if (pos > 1) {
    v[pos - 1] = a[pos];
  }
  ans = max(ans, cnt());
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (true) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
