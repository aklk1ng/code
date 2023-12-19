#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  const int A = 1e9 + 1;
  int mil = A, costl = A, mxr = 0, costr = A;
  int mxlen = 0, costlen = 0;
  for (int i = 0; i < n; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    if (l < mil) {
      mil = l, costl = A;
    }
    if (l == mil) {
      costl = min(costl, c);
    }

    if (mxr < r) {
      mxr = r, costr = A;
    }
    if (r == mxr) {
      costr = min(costr, c);
    }

    if (mxlen < r - l + 1) {
      mxlen = r - l + 1, costlen = A;
    }
    if (mxlen == r - l + 1) {
      costlen = min(costlen, c);
    }

    int ans = costl + costr;
    if (mxlen == mxr - mil + 1) {
      ans = min(ans, costlen);
    }
    cout << ans << '\n';
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
