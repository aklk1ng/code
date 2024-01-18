#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<ll> closed(n);
  ll sum = 0, cnt = 0, ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    sum -= cnt;
    cnt -= closed[i];
    b[i] -= sum;
    if (b[i] <= 0) {
      continue;
    }
    int el = min(i + 1, k);
    ll need = (b[i] + el - 1) / el;
    sum += need * el;
    cnt += need;
    ans += need;
    if (i - el >= 0) {
      closed[i - el] += need;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (false) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
