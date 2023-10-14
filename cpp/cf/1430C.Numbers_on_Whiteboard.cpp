#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  multiset<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < n - 1; i++) {
    auto it = s.end();
    it--;
    int a = *it;
    s.erase(it);
    it = s.end();
    it--;
    int b = *it;
    s.erase(it);
    s.insert((a + b + 1) / 2);
    ans.push_back({make_pair(a, b)});
  }
  cout << *s.begin() << '\n';
  for (auto &[i, j] : ans) {
    cout << i << ' ' << j << '\n';
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
