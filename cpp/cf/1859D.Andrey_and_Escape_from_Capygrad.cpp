#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> ans(n);
  vector<tuple<int, int, int>> events;
  for (int i = 0; i < n; i++) {
    int l, r, a, b;
    cin >> l >> r >> a >> b;
    ans[i] = b;
    events.emplace_back(b, 1, i);
    events.emplace_back(l, -1, i);
  }
  int q;
  cin >> q;
  vector<int> query(q);
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    query[i] = x;
    events.emplace_back(x, 0, i);
  }
  sort(events.begin(), events.end());
  reverse(events.begin(), events.end());
  multiset<int> s;
  for (auto &[x, type, id] : events) {
    if (type == 1) {
      if (!s.empty()) {
        ans[id] = *s.rbegin();
      }
      s.insert(ans[id]);
    } else if (type == 0) {
      if (!s.empty()) {
        query[id] = max(query[id], *s.rbegin());
      }
    } else {
      s.extract(ans[id]);
    }
  }

  for (auto &e : query) {
    cout << e << ' ';
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
