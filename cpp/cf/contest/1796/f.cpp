#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int A, B, N;
  std::cin >> A >> B >> N;

  std::vector<int> p(10);
  p[0] = 1;
  for (int i = 1; i < 10; i++) {
    p[i] = p[i - 1] * 10;
  }
  int P = p[5];
  std::set<std::array<ll, 3>> used;
  std::vector<int> len(P);
  for (int i = 0; i < P; i++) {
    len[i] = std::to_string(i).size();
  }
  auto divs = [&](int x) {
    std::vector<int> res;
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        res.push_back(i);
        if (i * i != x) {
          res.push_back(x / i);
        }
      }
    }
    return res;
  };
  for (int lenn = 1; lenn <= 9; ++lenn) {
    int x = p[lenn] - 1;
    for (int k2 : divs(x)) {
      int r = x / k2;
      for (int d = 1; d < P; ++d) {
        for (int lenb = len[d]; lenb <= 5; ++lenb) {
          int bg = p[lenb] - d * ll(r) % p[lenb];
          int dd = d / std::__gcd(d, bg);
          int lb = (p[lenb - 1] + bg - 1) / bg;
          int rb = (p[lenb] - 1) / bg;
          for (int g = (lb + dd - 1) / dd * dd; g <= rb; g += dd) {
            int b = bg * g;
            if (b >= B || std::__gcd(b / d, r) != 1)
              continue;
            int ag = (d * ll(r) + bg) / p[lenb];
            ll n = b / d * ll(k2) * ag;
            if (n < N && ag * g < A && std::__gcd(ag, bg) == 1 &&
                std::to_string(n).size() == lenn)
              used.insert({ag * g, b, n});
          }
        }
      }
    }
  }

  int ans = 0;
  for (auto &[a, b, n] : used) {
    int lenn = std::to_string(n).size();
    int lenb = std::to_string(b).size();
    ans += a * b * p[lenn] + n * b == a * n * p[lenb] + a * b;
  }
  std::cout << ans << '\n';
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
