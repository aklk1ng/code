#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  k--;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = k - 1, r = k + 1;
  ll now = a[k];
  while (true) {
    int prel = l, prer = r, pl = l, pr = r;
    ll mxr = now, mxl = now;
    while (r < n && a[r] + now >= 0) {
      now += a[r];
      if (now >= mxr) {
        mxr = now;
        pr = r + 1;
      }
      r++;
    }
    if (r == n) {
      break;
    }
    now = mxr;
    r = pr;
    while (l >= 0 && a[l] + now >= 0) {
      now += a[l];
      if (now >= mxl) {
        mxl = now;
        pl = l - 1;
      }
      l--;
    }
    if (l == -1) {
      break;
    }
    now = mxl;
    l = pl;
    if (prel == l && prer == r) {
      break;
    }
  }
  cout << (l == -1 || r == n ? "Yes" : "No") << '\n';
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
