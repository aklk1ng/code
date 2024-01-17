#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<pair<int, int>> ev(n);
  for (int i = 0; i < n; i++) {
    ev[i] = {(i + 1) / (b[i] + 1) + 1, i};
  }
  sort(ev.begin(), ev.end());
  set<pair<int, int>> s;
  int j = 0;
  for (int i = 1; i <= n; i++) {
    while (j < n && ev[j].first == i) {
      int id = ev[j++].second;
      s.insert({b[id] ? (id + 1) / b[id] : n, id});
    }
    a[s.begin()->second] = i;
    s.erase(s.begin());
  }
  for (auto &e : a) {
    cout << e << " \n"[e == a.back()];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (true) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
