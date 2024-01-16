#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, t;
  cin >> n >> t;
  vector at(n + 1, vector<pair<int, int>>());
  for (int i = 0; i < n; i++) {
    int a, x;
    cin >> a >> x;
    at[a].emplace_back(x, i);
  }

  vector<int> ans;
  set<pair<int, int>> s;
  int sum = 0;
  for (int k = n; k > 0; k--) {
    for (auto &e : at[k]) {
      sum += e.first;
      s.emplace(e);
    }
    while ((int)s.size() > k) {
      sum -= prev(s.end())->first;
      s.erase(prev(s.end()));
    }
    if ((int)s.size() == k && sum <= t) {
      for (auto &e : s) {
        ans.push_back(e.second);
      }
      break;
    }
  }

  int sz = ans.size();
  cout << sz << '\n';
  cout << sz << '\n';
  for (int i = 0; i < sz; i++) {
    cout << ans[i] + 1 << " \n"[i == sz - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
