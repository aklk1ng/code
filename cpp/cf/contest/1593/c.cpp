#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> x(k);
  for (int i = 0; i < k; i++) {
    cin >> x[i];
  }
  sort(x.rbegin(), x.rend());

  int cnt = 0;
  ll ans = 0;
  while (cnt < (int)x.size() && ans + n - x[cnt] < n) {
    ans += n - x[cnt++];
  }
  cout << cnt << '\n';
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
