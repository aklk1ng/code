#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void shift(std::multiset<int> &l, std::multiset<int> &r, int val) {
  l.erase(l.find(val));
  r.insert(val);
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  bool ok = false;
  std::multiset<int> lf, mid(a.begin(), a.end()), rg;
  auto check = [&]() {
    if (ok || lf.empty() || mid.empty() || rg.empty()) {
      return;
    }
    if (*lf.rbegin() == *mid.begin() && *mid.begin() == *rg.rbegin()) {
      ok = true;
      std::cout << "YES\n";
      std::cout << lf.size() << ' ' << mid.size() << ' ' << rg.size() << '\n';
    }
  };

  int r = n - 1;
  for (int l = 0; l < n - 2; l++) {
    shift(mid, lf, a[l]);
    while (r - 1 >= l && a[r] <= *lf.rbegin()) {
      shift(mid, rg, a[r]);
      r--;
    }
    while (r - 1 < l) {
      shift(rg, mid, a[r + 1]);
      r++;
    }
    check();

    shift(lf, mid, a[l]);
    check();
    shift(mid, lf, a[l]);

    if (rg.empty()) {
      continue;
    }

    shift(rg, mid, a[r + 1]);
    check();
    shift(mid, rg, a[r + 1]);
  }

  if (!ok) {
    std::cout << "NO\n";
  }
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
