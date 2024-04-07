#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string t = "CDHS";
  std::string s;
  std::cin >> s;
  int pos = t.find(s[0]);

  std::vector bs(4, std::vector<int>());
  for (int i = 0; i < 2 * n; i++) {
    std::string tmp;
    std::cin >> tmp;
    bs[t.find(tmp[1])].push_back(tmp[0] - '2');
  }

  std::vector<std::string> ans, l;
  for (int i = 0; i < 4; i++) {
    std::sort(bs[i].begin(), bs[i].end());
    if (i == pos) {
      continue;
    }
    if (bs[i].size() % 2) {
      int x = bs[i].back();
      l.push_back(std::string() + char('2' + x) + t[i]);
      bs[i].pop_back();
    }
    for (int j = 0; j < (int)bs[i].size(); j++) {
      int x = bs[i][j];
      ans.push_back(std::string() + char('2' + x) + t[i]);
    }
  }
  if (l.size() > bs[pos].size()) {
    std::cout << "IMPOSSIBLE\n";
    return;
  }
  for (auto &e : l) {
    ans.push_back(e);
    int x = bs[pos].back();
    bs[pos].pop_back();
    ans.push_back(std::string() + char('2' + x) + t[pos]);
  }
  for (int j = 0; j < (int)bs[pos].size(); j++) {
    int x = bs[pos][j];
    ans.push_back(std::string() + char('2' + x) + t[pos]);
  }

  for (int i = 0; i < 2 * n; i += 2) {
    std::cout << ans[i] << ' ' << ans[i + 1] << '\n';
  }
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
