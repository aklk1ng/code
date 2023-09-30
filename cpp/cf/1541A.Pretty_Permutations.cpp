#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    for (int i = 2; i <= n; i++) {
      cout << i << ' ' << i - 1 << ' ';
    }
    cout << '\n';
  } else {
    cout << 3 << ' ' << 1 << ' ' << 2 << ' ';
    for (int i = 6; i <= n; i++) {
      cout << i << ' ' << i - 1 << ' ';
    }
    cout << '\n';
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
