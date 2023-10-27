#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  if ((int)cnt.size() == 1) {
    cout << 0 << '\n';
  } else {
    int t = -1;
    for (auto &[k, v] : cnt) {
      t = max(t, v);
    }
    int ans = 0;
    while (t < n) {
      ans++;
      ans += min(t, n - t);
      t *= 2;
    }
    cout << ans << '\n';
  }
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
