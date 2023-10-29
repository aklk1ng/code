#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> p;
  for (int i = n + 1;; i++) {
    int t = 1;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        t = 0;
        break;
      }
    }
    if (t) { 
      p.push_back(i);
      break;
    }
  }
  for (int i = p.back() + n; ; i++) {
    int t = 1;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        t = 0;
        break;
      }
    }
    if (t) { 
      p.push_back(i);
      break;
    }
  }

  cout << min(1LL * p[0] * p[1], 1LL * p[0] * p[0] * p[0]) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
