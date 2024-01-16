#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 5e5 + 5;

void solve() {
  int q;
  cin >> q;
  vector<int> t(q), x(q), y(q);
  for (int i = 0; i < q; i++) {
    cin >> t[i] >> x[i];
    if (t[i] == 2) {
      cin >> y[i];
    }
  }
  vector<int> p(N);
  iota(p.begin(), p.end(), 0);
  vector<int> ans;
  for (int i = q - 1; i >= 0; i--) {
    if (t[i] == 1) {
      ans.push_back(p[x[i]]);
    } else {
      p[x[i]] = p[y[i]];
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto &e : ans) {
    cout << e << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  if (false) {
    cin >> tt;
  }
  while (tt--) {
    solve();
  }

  return 0;
}
