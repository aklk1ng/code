#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  {}
  int n;
  cin >> n;
  while (1) {
    int k = uniform_int_distribution<int>(2, n - 1)(rng);
    int l = n - k - 1;
    if (k != l && k != 1 && l != 1 && gcd(k, l) == 1) {
      cout << k << ' ' << l << ' ' << 1 << '\n';
      return;
    }
  }
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
