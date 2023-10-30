#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int k, n;
  cin >> k >> n;
  auto cal = [&](int f, int x) {
    vector<int> res;
    for (int i = 0; i < x; i++) {
      if (i < f - 1) {
        res.push_back(i + 2);
      } else {
        res.push_back(1);
      }
    }
    return res;
  };

  int ans = 1;
  for (int i = 1; i <= k; i++) {
    vector<int> t = cal(i, k - 1);
    if (accumulate(t.begin(), t.end(), 0) <= n - 1) {
      ans = i;
    }
  }

  vector<int> res;
  res.push_back(1);
  vector<int> t = cal(ans, k - 1);
  for (auto &e : t) {
    res.push_back(res.back() + e);
  }

  for (auto &e : res) {
    cout << e << " \n"[e == res.back()];
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
