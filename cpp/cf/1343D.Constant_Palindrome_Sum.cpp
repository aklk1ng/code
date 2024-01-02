#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> cnt(2 * k + 1), pre(2 * k + 2);
  for (int i = 0; i < n / 2; i++) {
    cnt[a[i] + a[n - i - 1]]++;
  }
  for (int i = 0; i < n / 2; i++) {
    int l1 = 1 + a[i], r1 = k + a[i];
    int l2 = 1 + a[n - i - 1], r2 = k + a[n - i - 1];
    pre[min(l1, l2)]++;
    pre[max(r1, r2) + 1]--;
  }
  for (int i = 1; i <= 2 * k + 1; i++) {
    pre[i] += pre[i - 1];
  }
  int ans = 1e9;
  for (int i = 2; i <= 2 * k; i++) {
    ans = min(ans, (pre[i] - cnt[i]) + (n / 2 - pre[i]) * 2);
  }
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
