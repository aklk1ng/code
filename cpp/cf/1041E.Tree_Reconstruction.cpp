#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    if (y != n) {
      cout << "NO\n";
      return;
    }
    cnt[x]++;
  }
  int cur = 0;
  for (int i = 1; i < n; i++) {
    cur += cnt[i];
    if (cur > i) {
      cout << "NO\n";
      return;
    }
  }
  int last = -1;
  cout << "YES\n";
  set<int> unused;
  for (int i = 1; i < n; i++) {
    unused.insert(i);
  }
  for (int i = 1; i < n; i++) {
    if (cnt[i] > 0) {
      unused.erase(i);
      if (last != -1) {
        cout << last << ' ' << i << '\n';
      }
      last = i;
      cnt[i]--;
    }
    while (cnt[i] > 0) {
      cout << last << ' ' << *unused.begin() << '\n';
      last = *unused.begin();
      cnt[i]--;
      unused.erase(unused.begin());
    }
  }
  cout << last << ' ' << n << '\n';
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
