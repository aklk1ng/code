#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  auto check = [&](int x) {
    multiset<int> s;
    for (auto &e : a) {
      s.insert(e);
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
      auto it1 = s.end();
      it1--;
      int y = x - *it1;
      s.erase(it1);
      auto it2 = s.find(y);
      if (it2 == s.end()) {
        return vector<int>();
      }
      res.push_back(x - y);
      res.push_back(y);
      x = max(x - y, y);
      s.erase(it2);
    }
    return res;
  };
  for (int i = 0; i < 2 * n - 1; i++) {
    int x = a[i] + a[2 * n - 1];
    vector<int> res = check(x);
    if (!res.empty()) {
      cout << "YES\n";
      cout << x << '\n';
      for (int j = 0; j < n; j++) {
        cout << res[2 * j] << ' ' << res[2 * j + 1] << '\n';
      }
      return;
    }
  }
  cout << "NO\n";
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
