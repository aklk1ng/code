#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  if (k == 1) { 
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
      cout << i << '\n';
    }
    return;
  }

  if (n % 2) {
    cout << "No\n";
    return;
  }

  cout << "Yes\n";
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n * k; j += n) {
      cout << j << ' ';
    }
    cout << '\n';
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
