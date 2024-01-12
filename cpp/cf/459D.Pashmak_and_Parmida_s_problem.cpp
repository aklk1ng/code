#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e6 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), tot(n), cnt(N), rem(N), fen(N);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tot[i] = a[i];
  }
  auto add = [&](int x, int y) {
    for (int i = x + 1; i < N; i += i & (-i)) {
      fen[i] += y;
    }
  };
  auto get = [&](int x) {
    int res = 0;
    for (int i = x; i > 0; i -= i & (-i)) {
      res += fen[i];
    }
    return res;
  };
  auto sum = [&](int x, int y) { return get(y) - get(x); };
  sort(tot.begin(), tot.end());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(tot.begin(), tot.end(), a[i]) - tot.begin();
  }
  for (int i = n - 1; i >= 0; i--) {
    cnt[a[i]]++;
    add(cnt[a[i]], 1);
    rem[i] = cnt[a[i]];
  }

  fill(cnt.begin(), cnt.end(), 0);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    add(rem[i], -1);
    cnt[a[i]]++;
    ans += sum(1, cnt[a[i]]);
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
