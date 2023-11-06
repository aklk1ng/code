#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  int l = 1, r = n, cur = 1;
  while (l <= r) {
    cout << ((cur ^= 1) ? l++ : r--) << ' ' ;
  }
  cout << '\n';
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
