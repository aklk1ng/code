// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::unordered_map<int, int> rooms;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    rooms[tmp]++;
  }
  for (auto &[k, v] : rooms)
    sum += v;

  for (int i = 0; i < q; i++) {
    int tmp;
    std::cin >> tmp;
    std::cout << sum - rooms[tmp] << std::endl;
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
