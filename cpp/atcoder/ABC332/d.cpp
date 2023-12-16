#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int h, w;
  cin >> h >> w;
  vector a(h + 1, vector<int>(w + 1));
  vector b(h + 1, vector<int>(w + 1));
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> b[i][j];
    }
  }

  vector<int> p(6), q(6);
  for (int i = 1; i <= h; i++) {
    p[i] = i;
  }
  for (int i = 1; i <= w; i++) {
    q[i] = i;
  }

  int ans = 1e9;
  do {
    do {
      bool ok = true;
      for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
          if (a[p[i]][q[j]] != b[i][j]) {
            ok = false;
          }
        }
      }
      if (!ok) {
        continue;
      }

      int pinv = 0, qinv = 0;
      for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= h; j++) {
          if (i < j && p[i] > p[j]) {
            pinv++;
          }
        }
      }
      for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= w; j++) {
          if (i < j && q[i] > q[j]) {
            qinv++;
          }
        }
      }
      ans = min(ans, pinv + qinv);
    } while (next_permutation(q.begin(), q.end()));
  } while (next_permutation(p.begin(), p.end()));

  cout << (ans == 1e9 ? -1 : ans) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
