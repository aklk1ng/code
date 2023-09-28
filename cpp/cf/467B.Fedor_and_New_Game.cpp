#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

int bit(int x) {
  int res = 0;
  while (x) {
    if (x & 1) {
      res++;
    }
    x >>= 1;
  }
  return res;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(m + 2);
  for (int i = 1; i <= m + 1; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (bit(a[i] ^ a[m + 1]) <= k) {
      ans++;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
