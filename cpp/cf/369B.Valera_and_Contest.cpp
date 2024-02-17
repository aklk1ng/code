#include <bits/stdc++.h>

typedef long long ll;

void solve() {
  int n, k, l, r, s, sk;
  std::cin >> n >> k >> l >> r >> s >> sk;
  int t = s - sk;
  std::vector<int> ans(n);
  for (int i = 0; i < k; i++) {
    ans[i] = sk / k;
    if (sk % k) {
      ans[i]++;
      sk--;
    }
  }
  if (k != n) {
    for (int i = k; i < n; i++) {
      ans[i] = t / (n - k);
      if (t % (n - k)) {
        ans[i]++;
        t--;
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < k; i++) {
    if (ans[i] < l || ans[i] > r) {
      ok = false;
    }
    for (int j = k; j < n; j++) {
      if (ans[j] > ans[i]) {
        ok = false;
      }
      if (ans[j] < l || ans[j] > r) {
        ok = false;
      }
    }
  }
  std::random_device rd;
  std::mt19937 gen(rd());
  std::shuffle(ans.begin(), ans.end(), gen);
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << " \n"[i == n - 1];
  }
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
