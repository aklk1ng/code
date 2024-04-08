#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;
const int N = 3e5 + 5;

int n, m, q, isi, isj;
std::vector<int> di{-1, 0, 1, 0}, dj{0, -1, 0, 1},
    dI{0, 0, -1, 1, -1, -1, 1, 1}, dJ{-1, 1, 0, 0, -1, 1, 1, -1};
std::vector<std::string> a(N);
std::vector<std::vector<int>> dist(N);
std::queue<std::pair<int, int>> Q;
std::vector<std::vector<bool>> reach(N), vis(N);

bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; };

bool onBorder(int i, int j) {
  return i == 0 || i == n - 1 || j == 0 || j == m - 1;
};

bool reachBorder(int i, int j) {
  if (!valid(i, j) || reach[i][j] || vis[i][j]) {
    return false;
  }

  if (onBorder(i, j)) {
    return true;
  }
  vis[i][j] = true;

  bool ok = false;
  for (int d = 0; d < 8; d++) {
    ok |= reachBorder(i + dI[d], j + dJ[d]);
  }
  return ok;
};

void get(int i, int j, int mi) {
  if (!valid(i, j) || reach[i][j] || dist[i][j] < mi || a[i][j] == '#') {
    return;
  }
  reach[i][j] = true;

  for (int d = 0; d < 4; d++) {
    get(i + di[d], j + dj[d], mi);
  }
};

bool cal(int x, int y, int mi) {
  for (int i = 0; i < n; i++) {
    reach[i] = std::vector<bool>(m, false);
    vis[i] = std::vector<bool>(m, false);
  }
  get(x, y, mi);

  return !reachBorder(isi, isj);
};

void solve() {
  std::cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    dist[i] = std::vector<int>(m, 1e9);

    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'v') {
        dist[i][j] = 0;
        Q.push({i, j});
      }
      if (a[i][j] == '#') {
        isi = i;
        isj = j;
      }
    }
  }

  while (!Q.empty()) {
    auto [i, j] = Q.front();
    Q.pop();

    for (int d = 0; d < 4; d++) {
      int ni = i + di[d], nj = j + dj[d];
      if (valid(ni, nj) && dist[i][j] + 1 < dist[ni][nj]) {
        dist[ni][nj] = dist[i][j] + 1;
        Q.push({ni, nj});
      }
    }
  }
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;

    int l = 0, r = n + m;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      cal(x, y, mid) ? l = mid : r = mid - 1;
    }
    std::cout << l << '\n';
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
