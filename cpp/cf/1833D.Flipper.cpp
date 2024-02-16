#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }

  int r = 0;
  for (int i = 0; i < n; i++) {
    if (p[std::min(n - 1, r + 1)] <= p[std::min(n - 1, i + 1)]) {
      r = i;
    }
  }

  std::vector<int> ans;
  for (int i = r + 1; i < n; i++) {
    ans.emplace_back(p[i]);
  }
  ans.emplace_back(p[r]);
  for (int i = r - 1; i >= 0; i--) {
    if (p[i] > p[0]) {
      ans.emplace_back(p[i]);
    } else {
      for (int j = 0; j <= i; j++) {
        ans.emplace_back(p[j]);
      }
      break;
    }
  }
  for (auto &e : ans) {
    std::cout << e << ' ';
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
