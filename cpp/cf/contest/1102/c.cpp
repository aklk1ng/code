#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int cur;
    cin >> cur;
    if (cur <= x) {
      cnt++;
    }
  }
  if (x > y) {
    cout << n << '\n';
  } else {
    cout << (cnt + 1) / 2 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
