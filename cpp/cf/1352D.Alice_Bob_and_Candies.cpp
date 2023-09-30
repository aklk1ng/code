#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  int ansl = 0, ansr = 0;
  int suml = 0, sumr = 0;
  int l = 1, r = n;
  while (l <= r) {
    if (cnt % 2 == 0) {
      int tmp = 0;
      while (l <= r && tmp <= sumr) {
        tmp += a[l++];
      }
      ansl += tmp;
      suml = tmp;
    } else {
      int tmp = 0;
      while (l <= r && tmp <= suml) {
        tmp += a[r--];
      }
      ansr += tmp;
      sumr = tmp;
    }
    cnt++;
  }
  cout << cnt << ' ' << ansl << ' ' << ansr << '\n';
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
