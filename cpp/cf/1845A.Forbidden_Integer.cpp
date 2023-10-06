#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  if (x != 1) {
    cout << "Yes\n";
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
      cout << 1 << " \n"[i == n - 1];
    }
  } else if (k == 1 || (k == 2 && n % 2 == 1)) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    cout << n / 2 << '\n';
    for (int i = 0; i < n / 2 - 1; i++) {
      if (i & 1) {
        cout << 3 << ' ';
      } else {
        cout << 2 << ' ';
      }
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
