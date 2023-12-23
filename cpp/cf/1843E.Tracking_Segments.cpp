#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> segs(m);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    segs[i] = {l, r};
  }
  int q;
  cin >> q;
  vector<int> ord(q);
  for (int i = 0; i < q; i++) {
    cin >> ord[i];
    ord[i]--;
  }

  int l = 0, r = q + 1;
  while (l + 1 != r) {
    int mid = l + (r - l) / 2;
    vector<int> cur(n);
    for (int i = 0; i < mid; i++) {
      cur[ord[i]] = 1;
    }
    vector<int> pr(n + 1);
    for (int i = 0; i < n; i++) {
      pr[i + 1] = pr[i] + cur[i];
    }
    bool ok = false;
    for (auto &e : segs) {
      if (pr[e.second] - pr[e.first] > (e.second - e.first) / 2) {
        ok = true;
        break;
      }
    }
    if (ok) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (r == q + 1) {
    r = -1;
  }
  cout << r << '\n';
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
