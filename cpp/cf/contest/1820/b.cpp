#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  std::string s;
  std::cin >> s;

  s += s;
  int k = 0, z = 0;
  for (char c : s) {
    z = c == '1' ? z + 1 : 0;
    k = std::max(k, z);
  }
  const int n = s.size() / 2;

  if (k > n) {
    std::cout << (ll)n * n << '\n';
  } else {
    const ll side_a = (k + 1) / 2;
    const ll side_b = (k + 2) / 2;
    std::cout << (k + 1) / 2 * (k + 2) /2  << '\n';
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
