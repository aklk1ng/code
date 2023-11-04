#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  int k = 0;
  while ((1 << (k + 1) <= n - 1)) {
    k++;
  }
  for (int i = (1 << k) - 1; i >= 0; i--) {
    cout << i << ' ';
  }
  for (int i = (1 << k); i < n; i++) {
    cout << i << " \n"[i == n - 1];
  }
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
