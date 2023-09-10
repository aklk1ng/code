// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
#define ll long long
const int N = 2e5 + 5;
ll a[N], t[N];
vector<int> X;

int lowbit(int x) { return x & -x; }

int getidx(int x) { return lower_bound(X.begin(), X.end(), x) - X.begin() + 1; }

void update(int k, ll v) {
  for (int i = k; i <= X.size(); i += lowbit(i)) {
    t[i] += v;
  }
}

ll getsum(int k) {
  ll res = 0;
  for (int i = k; i > 0; i -= lowbit(i)) {
    res += t[i];
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    X.push_back(a[i]);
  }
  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += getsum(X.size()) - getsum(getidx(a[i]));
    update(getidx(a[i]), 1);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // int t;
  // cin >> t;
  // while (t--) {
  //   solve();
  // }
  solve();

  return 0;
}
