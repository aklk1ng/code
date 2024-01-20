#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  string st;
  cin >> st;
  vector<pair<int, int>> ranges;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    ranges.push_back({l, r});
  }
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(i);
  }
  vector<int> v;
  vector<int> pos(n, -1);
  for (int i = 0; i < m; i++) {
    auto it = s.lower_bound(ranges[i].first);
    vector<int> tmp;
    while (it != s.end() && (*it) <= ranges[i].second) {
      tmp.push_back(*it);
      v.push_back(tmp.back());
      pos[tmp.back()] = v.size() - 1;
      it++;
    }
    while (tmp.size()) {
      s.erase(tmp.back());
      tmp.pop_back();
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (st[i] == '1') {
      cnt++;
    }
  }

  int ans = 0;
  for (int i = 0; i < min(cnt, (int)v.size()); i++) {
    if (st[v[i]] == '0') {
      ans++;
    }
  }
  while (q--) {
    int x;
    cin >> x;
    x--;
    if (pos[x] != -1 && pos[x] < cnt) {
      if (st[x] == '0') {
        ans--;
      } else {
        ans++;
      }
    }
    if (st[x] == '0') {
      st[x] = '1';
      cnt++;
      if (cnt <= (int)v.size() && st[v[cnt - 1]] == '0') {
        ans++;
      }
    } else {
      st[x] = '0';
      if (cnt > 0 && cnt <= (int)v.size() && st[v[cnt - 1]] == '0') {
        ans--;
      }
      cnt--;
    }
    cout << ans << '\n';
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
