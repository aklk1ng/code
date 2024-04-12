#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  ll n;
  std::cin >> n;
  ll cur = n;
  int p = 0;
  if (__builtin_popcountll(n) % 2) {
    std::cout << "secoNd" << std::endl;
  } else {
    std::cout << "firSt" << std::endl;
    p = 1;
  }

  int turn = 0;
  while (1) {
    if (turn % 2 == p) {
      ll p1, p2;
      std::cin >> p1 >> p2;
      if (!p1 && !p2) {
        break;
      }
      if (__builtin_popcountll(p1) % 2 == 0) {
        cur = p1;
      } else {
        cur = p2;
      }
    } else {
      int pos = 0;
      for (int i = 0; (1LL << i) < cur; i++) {
        if (cur & (1LL << i)) {
          pos = i;
        }
      }
      ll p1 = 1LL << pos, p2 = cur ^ p1;
      std::cout << p1 << ' ' << p2 << std::endl;
      cur = p1;
    }
    turn++;
  }
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
