#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int k, l, m, n, d;
  cin >> k >> l >> m >> n >> d;
  int ans = 0;
  for (int i = 1; i <= d; i++) {
    if (!(i % k) || !(i % l) || !(i % m) || !(i % n)) {
      ans++;
    }
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
