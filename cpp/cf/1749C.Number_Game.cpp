#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    multiset<int> s(a.begin(), a.end());
    for (int j = 0; j < i; j++) {
      auto it = s.upper_bound(i - j);
      if (it == s.begin()) {
        break;
      }
      s.erase(--it);
      if (!s.empty()) {
        int x = *s.begin();
        s.erase(s.begin());
        s.insert(x + i - j);
      }
    }
    if ((int)s.size() + i == n) {
      ans = i;
    }
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
