#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  int len = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (a[i % n] == 1) {
      len++;
      ans = max(ans, len);
    } else {
      len = 0;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
