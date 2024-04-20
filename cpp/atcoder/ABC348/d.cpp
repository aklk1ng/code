#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
constexpr std::array<std::pair<int, int>, 4> dxy{
    {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};

void solve() {
  int H, W;
  std::cin >> H >> W;
  std::vector<std::string> A(H);
  int sx = -1, sy = -1, gx = -1, gy = -1;
  for (int i = 0; i < H; i++) {
    std::cin >> A[i];
    for (int j = 0; j < W; j++) {
      if (A[i][j] == 'S') {
        sx = i;
        sy = j;
      } else if (A[i][j] == 'T') {
        gx = i;
        gy = j;
      }
    }
  }
  int N;
  std::cin >> N;
  std::vector<int> R(N), C(N), E(N);
  for (int i = 0; i < N; i++) {
    std::cin >> R[i] >> C[i] >> E[i];
    R[i]--, C[i]--;
  }

  std::vector s(H, std::vector<int>(W)), dp(H, std::vector<int>(W, -1));
  for (int i = 0; i < N; i++) {
    s[R[i]][C[i]] = E[i];
  }
  dp[sx][sy] = 0;
  std::queue<std::pair<int, int>> q;
  q.push({sx, sy});
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    int d = std::max(dp[x][y], s[x][y]);
    if (d <= 0) {
      continue;
    }

    for (auto &[nx, ny] : dxy) {
      int fx = x + nx, fy = y + ny;
      if (fx < 0 || fx >= H || fy < 0 || fy >= W || A[fx][fy] == '#') {
        continue;
      }
      if (dp[fx][fy] < d - 1) {
        dp[fx][fy] = d - 1;
        q.push({fx, fy});
      }
    }
  }
  std::cout << (dp[gx][gy] == -1 ? "No" : "Yes") << '\n';
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
