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
  vector<int> ok(n);
  for (int i = 0; i < n - 1; i++) {
    ok[i] = a[i] < 2 * a[i + 1];
  }
  int tot = 0;
  for (int i = 0; i < k; i++) {
    tot += ok[i];
  }

  int ans = 0;
  if (tot == k) {
    ans++;
  }
  for (int i = k; i < n - 1; i++) {
    tot += ok[i];
    tot -= ok[i - k];
    if (tot == k) {
      ans++;
    }
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
