#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, a;
  cin >> n >> a;
  vector<int> t(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }

  int ans = t[a];
  for (int i = 1; i <= n; i++) {
    if (a - i >= 1 && a + i <= n) {
      ans += (t[a - i] & t[a + i] ? 2 : 0);
    } else if (a - i >= 1) {
      ans += t[a - i];
    } else if (a + i <= n) {
      ans += t[a + i];
    } else {
      break;
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
