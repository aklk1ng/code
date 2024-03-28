#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a, b, c;
  int x;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    a.push_back(x);
  }
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    b.push_back(x);
  }
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    c.push_back(x);
  }

  std::set<ll> sum;
  for (auto &i : a) {
    for (auto &j : b) {
      for (auto &k : c) {
        sum.insert(i + j + k);
      }
    }
  }

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    if (sum.count(x)) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
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
