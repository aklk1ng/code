// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl

void solve() {
  int n, m, k, b;
  std::cin >> n >> m >> k >> b;
  std::vector<int> trees(n);
  std::vector<int> highs(n);
  for (int i = 0; i < n; i++)
    std::cin >> trees[i];
  for (int i = 0; i < n; i++)
    std::cin >> highs[i];

  while (--m) {
    for (int i = 0; i < n; i++) {
      trees[i] += highs[i];
      if (trees[i] > k)
        trees[i] = b;
    }
  }
  for (auto &tree : trees)
    std::cout << tree << " ";
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
    std::cout << std::endl;
  }

  return 0;
}
