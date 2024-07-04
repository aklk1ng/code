#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, c;
  cin >> n >> c;
  map<int, int> m;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    m[x]++;
  }
  int ans = 0;
  for (auto &[k, v] : m) {
    ans += min(v, c);
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
