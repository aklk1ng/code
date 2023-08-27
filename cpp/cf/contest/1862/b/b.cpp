// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
const int N = 2e5 + 5;
int a[N];

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> res;

  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] >= a[i - 1])
      res.emplace_back(a[i]);
    else {
      res.emplace_back(a[i]);
      res.emplace_back(a[i]);
    }
  }

  std::cout << res.size() << '\n';
  for (int x : res)
    std::cout << x << ' ';
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
