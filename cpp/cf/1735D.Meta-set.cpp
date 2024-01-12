#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector a(n, vector<int>(k));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> a[i][j];
    }
  }
  map<vector<int>, int> cnt;
  auto get = [&](const vector<int> &l, const vector<int> &r) {
    vector<int> res(k);
    for (int i = 0; i < k; i++) {
      res[i] = (6 - (l[i] + r[i])) % 3;
    }
    return res;
  };
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      auto t = get(a[i], a[j]);
      cnt[t]++;
    }
  }

  ll ans = 0;
  for (auto &e : a) {
    ans += 1LL * cnt[e] * (cnt[e] - 1) / 2;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
