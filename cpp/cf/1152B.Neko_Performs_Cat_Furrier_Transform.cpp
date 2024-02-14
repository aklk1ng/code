#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int x;
  std::cin >> x;
  auto check = [&](int z) {
    int bit = 0;
    z++;
    while (z % 2 == 0) {
      z /= 2;
      bit++;
    }
    return z == 1;
  };
  auto msb = [&](int z) {
    for (int i = 20; i >= 0; i--) {
      if ((z >> i) & 1) {
        return i;
      }
    }
    return -1;
  };
  int i = 0;
  std::vector<int> a;
  while (!check(x)) {
    i++;
    if (i % 2 == 0) {
      x++;
      continue;
    }
    int r = msb(x);
    if ((1 << r) != x) {
      r++;
    }
    x = (x ^ ((1 << r) - 1));
    a.push_back(r);
  }
  std::cout << i << '\n';
  for (auto &e : a) {
    std::cout << e << " \n"[e == a.back()];
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
