#include <bits/stdc++.h>
typedef long long ll;

ll f(ll s, ll k) {
  ll x = (5 * k - s) / 40;
  x = std::min(x, k / 4);
  ll res = s * k;
  if (x > 0) {
    res = std::max(res, (s + 20 * x) * (k - 4 * x));
  }
  x = std::min(x + 1, k / 4);
  if (x > 0) {
    res = std::max(res, (s + 20 * x) * (k - 4 * x));
  }
  return res;
}

void solve() {
  ll s, k;
  std::cin >> s >> k;

  ll ans = s * k;
  if (s % 10 == 5) {
    ans = std::max(ans, (s + 5) * (k - 1));
  } else if (s % 10) {
    if (s % 2) {
      s += s % 10;
      k--;
    }
    for (int i = 0; i < 4; i++) {
      if (k > 0) {
        ans = std::max(ans, f(s, k));
      }
      s += s % 10;
      k--;
    }
  }
  std::cout << ans << '\n';
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
