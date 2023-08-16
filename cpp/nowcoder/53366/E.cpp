// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

int check(int x) {
  if (x <= 2)
    return 0;
  return check((x + 1) / 2 - 1) + 1;
}
void solve() {
  int n, m;
  std::cin >> n >> m;
  std::cout << (check(n) ^ check(m) ? "Alice" : "Bob") << std::endl;
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
