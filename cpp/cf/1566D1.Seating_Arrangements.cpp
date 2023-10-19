#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n * m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n * m; i++) {
    a[i].second = -a[i].second;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    sort(a.begin() + (m * i), a.begin() + (m * i + m));
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < j; k++) {
        if (a[m * i + k].second > a[m * i + j].second) {
          ans++;
        }
      }
    }
  }
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
