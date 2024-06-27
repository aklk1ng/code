#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  if (n & 1) {
    for (int i = 0; i < n; i++) {
      cout << 1 << " \n"[i == n - 1];
    }
  } else {
    cout << "1 3 ";
    for (int i = 2; i < n; i++) {
      cout << 2 << " \n"[i == n - 1];
    }
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
