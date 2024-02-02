#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::map<int, int> cnt;
  for (auto &e : a) {
    cnt[e]++;
  }
  std::set<std::pair<int, int>> s1, s2;
  int sum1 = 0;
  for (auto &e : cnt) {
    s2.insert({e.second, e.first});
  }

  int ans = INF, skip = 0;
  for (int x = 0; x <= n; x++) {
    if (s1.find({cnt[x - 1], x - 1}) != s1.end()) {
      sum1 -= cnt[x - 1];
      s1.erase({cnt[x - 1], x - 1});
    }
    if (s2.find({cnt[x - 1], x - 1}) != s2.end()) {
      s2.erase({cnt[x - 1], x - 1});
    }
    while (!s2.empty() && sum1 + s2.begin()->first <= k) {
      s1.insert(*s2.begin());
      sum1 += s2.begin()->first;
      s2.erase(s2.begin());
    }
    if (k < skip) {
      break;
    }
    int now = x + s2.size();
    if (!x) {
      now = std::max(1, (int)s2.size());
    }
    ans = std::min(ans, now - x);
    if (!cnt[x]) {
      skip++;
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
