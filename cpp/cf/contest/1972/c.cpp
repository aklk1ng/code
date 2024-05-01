#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  ll k;
  std::cin >> n >> k;
  std::vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());
  std::reverse(a.begin(), a.end());
  ll lst = a.back(), cnt = 1;
  a.pop_back();
  while (!a.empty() && lst == a.back()) {
    a.pop_back();
    cnt++;
  }
  while (!a.empty()) {
    ll d = a.back() - lst;
    if (k < d * cnt) {
      break;
    }
    k -= d * cnt;
    lst = a.back();
    while (!a.empty() && lst == a.back()) {
      a.pop_back();
      cnt++;
    }
  }
  lst += k / cnt;
  k %= cnt;
  cnt -= k;
  std::cout << lst * n - cnt + 1 << '\n';
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
