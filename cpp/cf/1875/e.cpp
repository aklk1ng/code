#include <bits/stdc++.h>
typedef long long ll;

const int N = 4e5 + 5;
std::vector<int> pw5(10), dp(N, INT_MAX);
std::queue<int> q;

inline void check(int &x, int y) {
  if (y < x) {
    x = y;
  }
}

inline int w(int mask, int i) { return (mask / pw5[i]) % 5; }

inline int f(int a, int b, int m) { return (a << 2) | (b << 1) | m; }

inline int g(int c, int d) { return (c << 1) | d; }

inline int work(int mask, int opt) {
  int ret = 0;
  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      for (int m = 0; m < 2; m++) {
        int x = w(mask, f(a, b, m)), c = x >> 1, d = x & 1;
        if (opt == 1) {
          c = c & d;
        } else if (opt == 2) {
          c = c | d;
        } else if (opt == 3) {
          d = c ^ d;
        } else {
          d = m ^ d;
        }
        ret += pw5[f(a, b, m)] * g(c, d);
      }
    }
  }
  return ret;
}

void init() {
  pw5[0] = 1;
  for (int i = 1; i <= 8; i++) {
    pw5[i] = pw5[i - 1] * 5;
  }
  int mask = 0;
  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      for (int m = 0; m < 2; m++) {
        mask += pw5[f(a, b, m)] * g(a, b);
      }
    }
  }
  dp[mask] = 0;
  q.push(mask);

  while (!q.empty()) {
    int s = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int t = work(s, i);
      if (dp[t] == INT_MAX) {
        dp[t] = dp[s] + 1;
        q.push(t);
      }
    }
  }
  for (int i = 0; i < pw5[8]; i++) {
    for (int j = 0; j < 8; j++) {
      if (w(i, j) == 4) {
        for (int x = 1; x <= 4; x++) {
          check(dp[i], dp[i - x * pw5[j]]);
        }
        break;
      }
    }
  }
}

void solve() {
  int a, b, c, d, m;
  std::cin >> a >> b >> c >> d >> m;
  int mask = pw5[8] - 1;
  for (int i = 0; i < 30; i++) {
    int A = (a >> i) & 1, B = (b >> i) & 1, C = (c >> i) & 1, D = (d >> i) & 1,
        M = (m >> i) & 1;
    if (w(mask, f(A, B, M)) == 4) {
      mask -= (4 - g(C, D)) * pw5[f(A, B, M)];
    } else if (w(mask, f(A, B, M)) != g(C, D)) {
      std::cout << "-1\n";
      return;
    }
  }

  std::cout << (dp[mask] < INT_MAX ? dp[mask] : -1) << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  init();
  while (T--) {
    solve();
  }

  return 0;
}
