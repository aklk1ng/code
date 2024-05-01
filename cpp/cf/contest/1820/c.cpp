#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::map<int, int> l, r;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    r[a[i]] = i;
    if (!l.count(a[i])) {
      l[a[i]] = i;
    }
  }

  auto cal = [&](std::vector<int> t) {
    std::sort(t.begin(), t.end());
    t.erase(std::unique(t.begin(), t.end()), t.end());
    int sz = t.size();
    for (int i = 0; i < sz; i++) {
      if (t[i] != i) {
        return i;
      }
    }
    return sz;
  };
  int mex = cal(a);
  if (l.count(mex + 1)) {
    int L = l[mex + 1], R = r[mex + 1];
    for (int i = L; i <= R; i++) {
      a[i] = mex;
    }
    int mx = cal(a);
    std::cout << (mx == mex + 1 ? "YES" : "NO") << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] > mex || (l[a[i]] != r[a[i]])) {
      std::cout << "YES\n";
      return;
    }
  }
  std::cout << "NO\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
