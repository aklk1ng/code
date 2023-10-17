#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> c(n);
  for (int i = 0; i < n ;i++) {
    c[i] = a[i] - b[i];
  }
  sort(c.begin(), c.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] <= 0) {
      continue;
    }
    int pos = lower_bound(c.begin(), c.end(), -c[i] + 1) - c.begin();
    ans += i - pos;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
