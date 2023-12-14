#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  if (n <= 2) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    int k = n % 2 == 0 ? n / 2 : (n + 1) / 2;
    cout << 1 << ' ' << k << '\n';
    cout << n - 1 << ' ';
    for (int i = 1; i <= n; i++) {
      if (i == k) {
        continue;
      }
      cout << i << ' ';
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
