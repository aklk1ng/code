#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  map<int, int> cnt;
  set<int> b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
    b.insert(x);
    b.insert(x + 1);
  }

  int ans = 0;
  int last = 0;
  for (auto &e : b) {
    int cur = cnt[e];
    ans += max(0, cur - last);
    last = cur;
  }

  cout << ans << '\n';
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
