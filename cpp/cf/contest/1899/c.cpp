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

  int ans = a[0];
  int mi = min(0, a[0]), sum = a[0];
  for (int i = 1; i < n; i++) {
    if (abs(a[i] % 2) == abs(a[i - 1] % 2)) {
      mi = 0;
      sum = 0;
    }
    sum += a[i];
    ans = max(ans, sum - mi);
    mi = min(mi, sum);
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
