#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  int ans = n / 2 + 1;
  cout << ans;
  for (int i = 1; i <= ans; i++) {
    cout << '\n' << i << ' ' << 1;
  }
  for (int i = 2; i <= n - ans + 1; i++) {
    cout << '\n' << ans << ' ' << i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
