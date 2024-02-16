#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s, a, t;
  std::cin >> s;
  auto modify = [&](int k) {
    std::string pre = s.substr(k - 1, n - k + 1);
    std::string suf = s.substr(0, k - 1);
    if (n % 2 == k % 2) {
      std::reverse(suf.begin(), suf.end());
    }
    return pre + suf;
  };
  a = modify(1);
  int k = 1;
  for (int i = 2; i <= n; i++) {
    t = modify(i);
    if (t < a) {
      a = t;
      k = i;
    }
  }
  std::cout << a << '\n' << k << '\n';
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
