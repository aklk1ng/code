#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  vector<int> pref(k + 1), suf(k + 1);
  for (int i = 1; i <= k; i++) {
    pref[i] = pref[i - 1];
    if (i % 2 == 0) {
      pref[i] += a[i - 1] - a[i - 2];
    }
  }
  for (int i = k - 1; i >= 0; i--) {
    suf[i] = suf[i + 1];
    if ((k - i) % 2 == 0) {
      suf[i] += a[i + 1] - a[i];
    }
  }
  int ans = 1e9;
  for (int i = 0; i < k; i += 2) {
    ans = min(ans, suf[i] + pref[i]);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
