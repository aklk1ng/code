#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    for (int i = 1; i <= n; i += 2) {
      cout << i + 1 << ' ' << i << ' ';
    }
    cout << '\n';
  } else {
    cout << 1 << ' ';
    for (int i = 2; i <= n; i += 2) {
      cout << i + 1 << ' ' << i << ' ';
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
