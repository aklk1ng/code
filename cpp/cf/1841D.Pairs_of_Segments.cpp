#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
  return a.second < b.second;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i].first >> s[i].second;
  }
  std::vector<std::pair<int, int>> pairs;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (std::max(s[i].first, s[j].first) <=
          std::min(s[i].second, s[j].second)) {
        pairs.push_back({std::min(s[i].first, s[j].first),
                         std::max(s[i].second, s[j].second)});
      }
    }
  }

  int ans = 0;
  std::sort(pairs.begin(), pairs.end(), cmp);
  int lst = -1;
  for (auto &e : pairs) {
    if (e.first > lst) {
      ans++;
      lst = e.second;
    }
  }

  std::cout << n - ans * 2 << '\n';
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
