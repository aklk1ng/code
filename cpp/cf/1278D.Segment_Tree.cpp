#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 5e5 + 5;

std::vector g(N, std::vector<int>());
std::vector<bool> used(N);

void dfs(int v, int p = -1) {
  used[v] = true;
  for (auto &to : g[v]) {
    if (to != p) {
      if (!used[to]) {
        dfs(to, v);
      }
    }
  }
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  std::vector<std::pair<int, int>> evs;
  for (int i = 0; i < n; i++) {
    evs.push_back({a[i].first, i});
    evs.push_back({a[i].second, i});
  }
  std::sort(evs.begin(), evs.end());

  int cnt = 0;
  std::set<std::pair<int, int>> cur;
  for (auto &e : evs) {
    if (cnt >= n) {
      break;
    }
    if (cur.count(e)) {
      cur.erase(e);
    } else {
      int i = e.second, r = a[i].second;
      for (auto &it : cur) {
        if (it.first > r) {
          break;
        }
        int j = it.second;
        g[i].push_back(j);
        g[j].push_back(i);
        cnt++;
        if (cnt >= n) {
          break;
        }
      }
      cur.insert({a[i].second, i});
    }
  }
  dfs(0);
  std::cout << (cnt == n - 1 && std::count(used.begin(), used.end(), 1) == n
                    ? "YES"
                    : "NO")
            << '\n';
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
