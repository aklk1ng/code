#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int t1 = INF, t2 = INF, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (t1 > t2) {
      swap(t1, t2);
    }
    if (a[i] <= t1) {
      t1 = a[i];
    } else if (a[i] <= t2) {
      t2 = a[i];
    } else {
      t1 = a[i];
      ans++;
    }
  }
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
