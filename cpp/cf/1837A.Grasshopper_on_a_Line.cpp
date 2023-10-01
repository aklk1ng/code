#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int x, k;
  cin >> x >> k;
  vector<int> pos;
  int cnt = 0;
  int cur = 0;
  while (cur < x) {
    int diff = x - cur;
    while (diff % k == 0) {
      diff--;
    }
    pos.push_back(diff);
    cur += diff;
    cnt++;
  }
  cout << cnt << '\n';
  for (auto &i : pos) {
    cout << i << ' ';
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
