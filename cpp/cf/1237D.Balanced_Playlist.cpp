#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(3 * n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i + n] = a[i + 2 * n] = a[i];
  }

  std::vector<int> ans(3 * n), mxs, mis;
  for (int i = 3 * n - 1; i >= 0; i--) {
    while (!mxs.empty() && a[mxs.back()] < a[i]) {
      mxs.pop_back();
    }
    while (!mis.empty() && a[mis.back()] > a[i]) {
      mis.pop_back();
    }
    int l = 0, r = mis.size();
    while (l < r) {
      int m = (l + r) / 2;
      if (a[mis[m]] * 2 < a[i]) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    int nxt = 3 * n;
    if (l > 0) {
      nxt = std::min(nxt, mis[l - 1]);
    }
    if (!mxs.empty()) {
      nxt = std::min(nxt, mxs.back());
    }
    if (nxt < 3 * n && a[nxt] >= a[i]) {
      ans[i] = ans[nxt];
    } else {
      ans[i] = nxt;
    }
    mis.push_back(i);
    mxs.push_back(i);
  }

  for (int i = 0; i < n; i++) {
    std::cout << (ans[i] == 3 * n ? -1 : ans[i] - i) << " \n"[i == n - 1];
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
