#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  int l = 0, r = n - 1;
  int suml = w[0], sumr = w[n - 1];
  int ans = 0;
  while (l < r) {
    if (suml == sumr) {
      ans = max(ans, l + 1 + n - r);
    }
    if (suml <= sumr) {
      suml += w[++l];
    } else {
      sumr += w[--r];
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
