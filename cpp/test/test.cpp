#include <bits/stdc++.h>
using namespace std;
const long long inf = 5e9;
#define ll long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int pre[N], cnt[N];

int root(int x) { return pre[x] = (pre[x] == x ? x : root(pre[x])); }

vector<ll> v;

bool check(ll mid) {
  ll tmp = 0;
  ll cnt1 = 0;
  for (auto &i : v) {
    if (i == 1) {
      cnt1++;
    } else {
      tmp += min(i, mid);
    }
  }
  tmp -= 2 * (v.size() - cnt1 - 1);
  return tmp >= cnt1;
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    pre[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    pre[root(u)] = root(v);
  }
  for (int i = 1; i <= n; i++) {
    cnt[root(i)]++;
  }
  for (int i = 1; i <= n; i++) {
    if (root(i) == i) {
      v.push_back(cnt[i]);
    }
  }
  ll l = -1, r = 1e9;
  while (l + 1 != r) {
    ll mid = l + (r - l) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << (check(r) ? r : -1) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // int tt;
  // cin >> tt;
  // while (tt--) {
  //   solve();
  // }
  solve();

  return 0;
}
