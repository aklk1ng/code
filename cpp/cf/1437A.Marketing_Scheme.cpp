#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int l, r;
  cin >> l >> r;
  cout << (2 * l > r ? "Yes" : "No") << '\n';
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
