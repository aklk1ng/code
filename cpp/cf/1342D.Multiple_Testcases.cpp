#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> c(k + 1);
  for (int i = 0; i < k; i++) {
    cin >> c[i + 1];
  }
  sort(a.begin(), a.end(), greater<int>());

  int ans = 0;
  for (int i = k, g = 0; i >= 1; i--) {
    while (g < n && a[g] == i) {
      g++;
    }
    ans = max(ans, (g + c[i] - 1) / c[i]);
  }
  vector res(ans, vector<int>());
  for (int i = 0; i < n; i++) {
    res[i % ans].push_back(a[i]);
  }

  cout << ans << '\n';
  for (int i = 0; i < ans; i++) {
    cout << res[i].size();
    for (auto &e : res[i]) {
      cout << ' ' << e;
    }
    cout << '\n';
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
