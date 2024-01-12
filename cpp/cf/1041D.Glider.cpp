#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, h;
  cin >> n >> h;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  vector<int> ps(n + 1);
  ps[0] = 0;
  for (int i = 0; i < n; i++) {
    ps[i + 1] = ps[i] + (a[i].second - a[i].first);
  }

  auto check = [&](int lf, int rg) {
    int l = lower_bound(a.begin(), a.end(), pair<int, int>(lf, -1)) - a.begin();
    int r = lower_bound(a.begin(), a.end(), pair<int, int>(rg, -1)) - a.begin();

    int sum = ps[r] - ps[l];
    if (l > 0) {
      sum += max(0, a[l - 1].second - lf);
    }
    return rg - sum - lf;
  };
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int lx = a[i].second + 1;
    int l = -(h + 1), r = lx;
    while (l + 1 != r) {
      int mid = (l + r) / 2;
      if (check(mid, lx) > h) {
        l = mid;
      } else {
        r = mid;
      }
      ans = max(ans, lx - r);
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
