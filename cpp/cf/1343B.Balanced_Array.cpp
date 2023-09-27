#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  n /= 2;
  if (n & 1) {
    cout << "No\n";
    return;
  } else {
    cout << "Yes\n";
  }
  for (int i = 1; i <= n; i++) {
    cout << i * 2 << ' ';
  }
  for (int i = 1; i < n; i++) {
    cout << i * 2 - 1 << ' ';
  }
  cout << 3 * n - 1 << '\n';
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
