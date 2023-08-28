// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

bool check(int i, int j, int k) {
  std::set<int> s;
  while (i) {
    s.insert(i % 10);
    i /= 10;
  }
  while (j) {
    s.insert(j % 10);
    j /= 10;
  }
  while (k) {
    s.insert(k % 10);
    k /= 10;
  }
  for (auto &i : s)
    if (i == 0)
      return false;

  return s.size() == 9;
}

void solve() {
  for (int i = 100; 3 * i < 1000; i++) {
    int j = 2 * i, k = 3 * i;
    if (check(i, j, k))
      std::cout << i << ' ' << j << ' ' << k << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
