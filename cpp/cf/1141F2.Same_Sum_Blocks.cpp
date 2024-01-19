#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, vector<pair<int, int>>> segs;
  for (int r = 0; r < n; r++) {
    int sum = 0;
    for (int l = r; l >= 0; l--) {
      sum += a[l];
      segs[sum].push_back({l, r});
    }
  }

  int ans = 0;
  vector<pair<int, int>> best;
  for (auto &e : segs) {
    const auto p = e.second;
    int cur = 0;
    int r = -1;
    vector<pair<int, int>> now;
    for (auto &seg : p) {
      if (seg.first > r) {
        cur++;
        now.push_back(seg);
        r = seg.second;
      }
    }
    if (cur > ans) {
      ans = cur;
      best = now;
    }
  }
  cout << ans << '\n';
  for (auto &e : best) {
    cout << e.first + 1 << ' ' << e.second + 1 << '\n';
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
