#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  std::set<int> s;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (s.empty() || a[i] < a[*s.rbegin()]) {
      s.insert(i);
    }
  }
  for (int i = 0; i < m; i++) {
    int j, d;
    std::cin >> j >> d;
    j--;
    a[j] -= d;
    auto it = s.upper_bound(j);
    if (it != s.begin()) {
      it = std::prev(it);
      if (*it == j || a[*it] > a[j]) {
        s.insert(j);
      }
    } else {
      s.insert(j);
    }
    while (true) {
      it = s.upper_bound(j);
      if (it != s.end() && a[*it] >= a[j]) {
        s.erase(it);
      } else {
        break;
      }
    }
    std::cout << s.size() << ' ';
  }
  std::cout << '\n';
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
