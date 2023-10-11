#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  cout << n - k + k / 2 << '\n';
  for (int i = k + 1; i <= n; i++) {
    cout << i << ' ';
  }
  for (int i = (k + 1) / 2; i < k; i++) {
    cout << i << " \n"[i == k - 1];
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
