#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int q, x;
  cin >> q >> x;
  vector<int> a(x);
  set<pair<int, int>> s;
  for (int i = 0; i < x; i++) {
    s.insert({a[i], i});
  }
  for (int i = 0; i < q; i++) {
    int cur;
    cin >> cur;
    cur %= x;
    s.erase({a[cur], cur});
    a[cur]++;
    s.insert({a[cur], cur});
    cout << s.begin()->first * x + s.begin()->second << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
