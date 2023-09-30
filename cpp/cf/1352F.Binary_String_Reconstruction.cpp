#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n0, n1, n2;
  cin >> n0 >> n1 >> n2;
  if (n1 == 0) {
    if (n0) {
      cout << string(n0 + 1, '0') << '\n';
    } else {
      cout << string(n2 + 1, '1') << '\n';
    }
    return;
  }
  string ans;
  for (int i = 0; i < n1 + 1; i++) {
    if (i & 1) {
      ans += '0';
    } else {
      ans += '1';
    }
  }
  ans.insert(1, string(n0, '0'));
  ans.insert(0, string(n2, '1'));
  cout << ans << '\n';
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
