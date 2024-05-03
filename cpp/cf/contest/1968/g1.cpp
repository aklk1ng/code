#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> k >> s;

  auto func = [&]() {
    std::vector<int> res(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
      if (i <= r) {
        res[i] = std::min(r - i + 1, res[i - l]);
      }
      while (i + res[i] < n && s[res[i]] == s[i + res[i]]) {
        res[i]++;
      }
      if (i + res[i] - 1 > r) {
        l = i;
        r = i + res[i] - 1;
      }
    }
    return res;
  };
  auto f = [&](std::vector<int> &z, int len) {
    int sz = z.size();
    int cnt = 1;
    for (int i = len; i < sz;) {
      if (z[i] >= len) {
        cnt++;
        i += len;
      } else {
        i++;
      }
    }
    return cnt;
  };
  auto z = func();
  int l = 0, r = n + 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (f(z, mid) >= k) {
      l = mid;
    } else {
      r = mid;
    }
  }
  std::cout << l << '\n';
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
