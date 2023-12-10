#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  if ((n % 2 == 0 && m % 2) || (m < n)) {
    cout << "No\n";
  } else if (n % 2) {
    cout << "Yes\n";
    for (int i = 1; i < n; i++) {
      cout << 1 << ' ';
    }
    cout << m - n + 1 << '\n';
  } else {
    cout << "Yes\n";
    for (int i = 2; i < n; i++) {
      cout << 1 << ' ';
    }
    cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << '\n';
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
