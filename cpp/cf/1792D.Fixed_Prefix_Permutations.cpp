#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  vector b(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[i][a[i][j]] = j;
    }
  }
  sort(b.begin(), b.end());
  auto get = [&](const vector<int> &l, const vector<int>  &r) {
    int res = 0;
    while (res < (int)l.size() && l[res] == r[res]) {
      res++;
    }
    return res;
  };
  for (int i = 0; i < n; i++) {
    int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    int ans = 0;
    if (j > 0) {
      ans = max(ans, get(a[i], b[j - 1]));
    }
    if (j < n) {
      ans = max(ans, get(a[i], b[j]));
    }
    cout << ans << ' ';
  }
  cout << '\n';
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
