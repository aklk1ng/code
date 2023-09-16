#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 10;
#define ll long long
const int N = 2e5 + 10;

void solve() {
  int n, m;
  cin >> n >> m;
  map<int, pair<int, int>> mp;
  mp[1] = {0, 0};
  while (m--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (mp.find(a) != mp.end() && mp.find(b) == mp.end()) {
      mp[b].first = mp[a].first + x;
      mp[b].second = mp[a].second + y;
    } else if (mp.find(b) != mp.end() && mp.find(a) == mp.end()) {
      mp[a].first = mp[b].first - x;
      mp[a].second = mp[b].second - y;
    } else if (mp.find(a) == mp.end() && mp.find(b) == mp.end()) {
      mp[a].first = inf;
      mp[a].second = inf;
      mp[b].first = inf;
      mp[b].second = inf;
    }
  }
  for (auto &[k, v] : mp) {
    if (v.first == inf) {
      cout << "undecidable\n";
    } else {
      cout << v.first << ' ' << v.second << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // int tt;
  // cin >> tt;
  // while (tt--) {
  //   solve();
  // }
  solve();
  return 0;
}
