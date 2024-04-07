#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> arr[i];
  }
  std::vector<ll> ps(n + 1);
  for (int i = 1; i <= n; i++) {
    ps[i] = ps[i - 1] + arr[i];
  }
  auto cnt = [&](ll x) { return (x * (x + 1)) / 2; };
  auto cal = [&](ll l, ll r, ll k) {
    ll x = ps[r] - ps[l - 1];
    if (x <= k) {
      return cnt(k) - cnt(k - x);
    } else {
      return cnt(k) - cnt(x - k - 1);
    }
  };
  std::vector<int> res;
  int q;
  std::cin >> q;
  while (q--) {
    ll l, u;
    std::cin >> l >> u;
    int lb = l, rb = n;
    while (rb - lb > 2) {
      ll a = (2 * lb + rb) / 3;
      ll b = (lb + 2 * rb) / 3;
      ll av = cal(l, a, u);
      ll bv = cal(l, b, u);
      if (av > bv) {
        rb = b;
      } else {
        lb = a;
      }
    }

    ll best = 0;
    int ind = lb;
    for (int i = std::min(lb, rb); i <= std::max(lb, rb); i++) {
      ll x = cal(l, i, u);
      if (best < x) {
        best = x;
        ind = i;
      }
    }
    res.push_back(ind);
  }

  for (auto &e : res) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
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
