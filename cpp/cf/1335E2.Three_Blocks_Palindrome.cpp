#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector cnt(200, vector<int>(n + 1)), pos(200, vector<int>());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 200; j++) {
      cnt[j][i + 1] = cnt[j][i];
    }
    cnt[a[i] - 1][i + 1]++;
    pos[a[i] - 1].push_back(i);
  }

  int ans = 0;
  for (int i = 0; i < 200; i++) {
    ans = max(ans, (int)pos[i].size());
    for (int p = 0; p < (int)pos[i].size() / 2; p++) {
      int l = pos[i][p] + 1, r = pos[i][pos[i].size() - p - 1] - 1;
      for (int k = 0; k < 200; k++) {
        int sum = cnt[k][r + 1] - cnt[k][l];
        ans = max(ans, (p + 1) * 2 + sum);
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
