#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans = 0;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    ans += cnt[a[i]];
    if (a[i] == 1) {
      ans += cnt[2];
    } else if (a[i] == 2) {
      ans += cnt[1];
    }
    cnt[a[i]]++;
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
