#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::string s(m, '0');
  std::vector<std::pair<int, int>> v(m);
  std::vector<int> sum(m + 1);
  auto ask = [&](const std::string &t) {
    std::cout << "? " << s << std::endl;
    int r;
    std::cin >> r;
    return r;
  };
  for (int i = 0; i < m; i++) {
    s[i] = '1';
    v[i] = {ask(s), i};
    s[i] = '0';
  }
  std::sort(v.begin(), v.end());
  for (int i = 0; i < m; i++) {
    s[v[i].second] = '1';
    sum[i + 1] = ask(s);
  }
  int r = 0;
  for (int i = 0; i < m; i++) {
    r += (sum[i + 1] == sum[i] + v[i].first) * v[i].first;
  }
  std::cout << "! " << r << std::endl;
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
