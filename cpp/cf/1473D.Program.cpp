#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> sul(1), sur(1);
  for (int i = n - 1; i >= 0; i--) {
    int d = s[i] == '+' ? 1 : -1;
    sul.push_back(min(0, sul.back() + d));
    sur.push_back(max(0, sur.back() + d));
  }
  reverse(sul.begin(), sul.end());
  reverse(sur.begin(), sur.end());
  vector<int> prl(1), prr(1), pr(1);
  for (int i = 0; i < n; i++) {
    int d = s[i] == '+' ? 1 : -1;
    pr.push_back(pr.back() + d);
    prl.push_back(min(prl.back(), pr.back()));
    prr.push_back(max(prr.back(), pr.back()));
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    int l1 = prl[l], r1 = prr[l];
    int l2 = sul[r] + pr[l], r2 = sur[r] + pr[l];
    cout << max(r1, r2) - min(l1, l2) + 1 << '\n';
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
