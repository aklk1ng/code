#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, q;
  cin >> n >> q;
  map<int, int> even, odd;
  vector<int> last(n + 1), lst(n + 1), pxor(n + 1), a(n + 1);
  even[0] = 0;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cur ^= a[i];
    pxor[i] = cur;
    if (!a[i]) {
      last[i] = last[i - 1];
    } else {
      last[i] = i;
    }
    if (i & 1) {
      if (even.count(cur)) {
        lst[i] = even[cur];
      }
      odd[cur] = i;
    } else {
      if (odd.count(cur)) {
        lst[i] = odd[cur];
      }
      even[cur] = i;
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (pxor[l - 1] != pxor[r]) {
      cout << -1 << '\n';
    } else if (last[r] < l) {
      cout << 0 << '\n';
    } else if (r % 2 == l % 2) {
      cout << 1 << '\n';
    } else if (!a[l] || !a[r]) {
      cout << 1 << '\n';
    } else if (lst[r] >= l) {
      cout << 2 << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (false) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
