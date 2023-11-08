#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(3);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x % 3]++;
  }
  int ans = cnt[0];
  int mi = min(cnt[1], cnt[2]);
  ans += mi;
  cnt[1] -= mi;
  cnt[2] -= mi;
  ans += (cnt[1] + cnt[2]) / 3;
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
