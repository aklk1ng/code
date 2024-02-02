#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 5e5 + 5;

std::vector<int> f(N);

void upd(int x) {
  for (int i = x; i < N; i |= i + 1) {
    f[i]++;
  }
}

int sum(int x) {
  int res = 0;
  for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
    res += f[i];
  }
  return res;
}

int get(int l, int r) {
  if (l > r) {
    return 0;
  }
  return sum(r) - sum(l - 1);
}

void solve() {
  int n, k, d;
  std::cin >> n >> k >> d;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());

  std::vector<int> dp(n + 1);
  dp[0] = 1;
  upd(0);

  int l = 0;
  for (int i = 0; i < n; i++) {
    while (l < i && a[i] - a[l] > d) {
      l++;
    }
    dp[i + 1] = (get(l, i - k + 1) >= 1);
    if (dp[i + 1]) {
      upd(i + 1);
    }
  }
  std::cout << (dp[n] ? "YES" : "NO") << '\n';
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
