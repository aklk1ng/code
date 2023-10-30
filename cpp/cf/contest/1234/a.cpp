#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int tot = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tot += a[i];
  }
  int l = 0, r = 1e7 + 1;
  while (l + 1 != r) {
    int m = l + (r - l) / 2;
    int diff = n * m - tot;
    if (diff >= 0) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << r << '\n';

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
