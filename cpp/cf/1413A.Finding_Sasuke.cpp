#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mi = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mi = lcm(mi, a[i]);
  }
  for (int i = 1; i < n; i += 2) {
    cout << -a[i] << ' ' << a[i - 1] << ' ';
  }
  cout << '\n';
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
