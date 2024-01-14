#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> segs(n);
  vector<int> cnt(N);
  vector<vector<int>> ev(N);
  for (int i = 0; i < n; i++) {
    cin >> segs[i].first >> segs[i].second;
    cnt[segs[i].first]++;
    cnt[segs[i].second + 1]--;
    ev[segs[i].first].push_back(i + 1);
    ev[segs[i].second + 1].push_back(-i - 1);
  }
  for (int i = 0; i < N - 1; i++) {
    cnt[i + 1] += cnt[i];
  }
  vector<int> ans(n), sub(N);
  set<pair<int, int>> s;
  int cur = 0;
  for (int i = 0; i < N; i++) {
    cur += sub[i];
    for (auto &e : ev[i]) {
      if (e > 0) {
        s.insert({segs[e - 1].second, e - 1});
      } else {
        auto it = s.find({segs[-e - 1].second, -e - 1});
        if (it != s.end()) {
          s.erase(it);
        }
      }
    }
    while (cnt[i] - cur > k) {
      int pos = s.rbegin()->second;
      s.erase(prev(s.end()));
      cur++;
      sub[segs[pos].second + 1]--;
      ans[pos] = 1;
    }
  }

  cout << accumulate(ans.begin(), ans.end(), 0) << '\n';
  for (int i = 0; i < n; i++) {
    if (ans[i]) {
      cout << i + 1 << ' ';
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
