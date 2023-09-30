#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  if (n < 4) {
    cout << -1 << '\n';
    return;
  }
  for (int i = n; i > 0; i--) {
    if (i & 1) {
      cout << i << ' ';
    }
  }
  cout << 4 << ' ' << 2 << ' ';
  for (int i = 6; i <= n; i += 2) {
    cout << i << ' ';
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
