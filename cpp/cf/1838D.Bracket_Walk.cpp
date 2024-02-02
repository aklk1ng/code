#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string s;
  std::cin >> s;
  std::set<int> a;
  for (int i = 1; i <= n; i++) {
    if ((i % 2) != (s[i - 1] == '(')) {
      a.insert(i);
    }
  }
  while (q--) {
    int i;
    std::cin >> i;
    if (a.count(i)) {
      a.erase(i);
    } else {
      a.insert(i);
    }

    if ((n % 2) || (!a.empty() && (*a.begin() % 2 || !(*a.rbegin() % 2)))) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
