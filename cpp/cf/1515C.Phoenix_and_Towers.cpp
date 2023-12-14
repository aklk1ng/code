#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> h(n + 1);
  set<pair<int, int>> s;
  cout << "Yes\n";
  for (int i = 1; i <= m; i++) {
    s.insert({0, i});
  }
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    auto t = *s.begin();
    s.erase(t);
    cout << t.second << ' ';
    s.insert({t.first + h[i], t.second});
  }

  cout << '\n';
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
