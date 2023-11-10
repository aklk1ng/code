#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  if (m % n && n != 1) {
    cout << -1 << '\n';
    return;
  } else {
    int diff = m / n;
    int ans = 0;
    while (!(diff % 2)) {
      diff /= 2;
      ans++;
    }
    while (!(diff % 3)) {
      diff /= 3;
      ans++;
    }
    if (diff == 1) {
      cout << ans << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
