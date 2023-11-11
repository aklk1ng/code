#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(2e5 + 5);
  if (n == 1) {
    cout << 1 << '\n';
  } else if (n == 2) {
    cout << 1 << ' ' << 2 << '\n';
  } else {
    int c = 4;
    fill(a.begin(), a.end(), 0);
    a[0] = 2;
    a[n / 2] = 1;
    a[n - 1] = 3;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        a[i] = c++;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
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
