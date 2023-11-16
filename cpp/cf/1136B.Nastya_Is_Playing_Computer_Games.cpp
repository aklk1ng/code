#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  cout << (2 * n + 1) + (n - 1) + min(k - 1, n - k) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
