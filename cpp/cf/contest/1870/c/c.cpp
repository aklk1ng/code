#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 2e5 + 5;

void solve() {
  ll n, k, x;
  cin >> n >> k >> x;
  if (k * (1 + k) / 2 > x || k * (n + n - k + 1) / 2 < x) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
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
