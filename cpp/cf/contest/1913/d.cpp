#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), mi(n), sum(n + 2), nxt(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  auto cal = [&](ll x) {
    x %= mod;
    if (x < 0) {
      x += mod;
    }
    return x;
  };
  std::stack<int> st;
  mi[n - 1] = n;
  sum[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && a[st.top()] > a[i]) {
      st.pop();
    }
    mi[i] = st.empty() ? n : st.top();
    st.push(i);

    int t1 = mi[i];
    int t2 = cal(sum[i + 1] - sum[t1 + 1]);
    if (t1 != n) {
      t2 = cal(t2 + nxt[t1]);
      nxt[i] = cal(sum[t1] - sum[t1 + 1] + nxt[t1]);
    }
    sum[i] = cal(t2 + sum[i + 1]);
  }

  int ans = 0;
  int mn = a[0];
  for (int i = 0; i < n; i++) {
    mn = std::min(mn, a[i]);
    if (a[i] == mn) {
      ans = cal(ans + sum[i] - sum[i + 1]);
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
