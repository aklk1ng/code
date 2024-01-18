#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 2e5 + 5;

int n;
vector<ll> bt(N), s(N);
vector<int> ans(N);

void update(int x, int delta) {
  for (; x <= n; x += x & -x) {
    bt[x] += delta;
  }
}

ll query(int x) {
  ll res = 0;
  for (; x > 0; x -= x & -x) {
    res += bt[x];
  }
  return res;
}

ll search(ll sum) {
  int num = 0;
  ll res = 0;
  for (int i = 21; i >= 0; i--) {
    if ((num + (1 << i) <= n) && (res + bt[num + (1 << i)] <= sum)) {
      num += (1 << i);
      res += bt[num];
    }
  }
  return num + 1;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    update(i, i);
    cin >> s[i];
  }
  for (int i = n; i >= 1; i--) {
    ans[i] = search(s[i]);
    update(ans[i], -ans[i]);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
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
