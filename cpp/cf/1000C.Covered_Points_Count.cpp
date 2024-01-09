#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  vector<ll> cval;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    cval.push_back(a[i].first);
    cval.push_back(a[i].second + 1);
  }
  sort(cval.begin(), cval.end());
  cval.resize(unique(cval.begin(), cval.end()) - cval.begin());

  vector<int> cnt(2 * n);
  for (auto &i : a) {
    int l = lower_bound(cval.begin(), cval.end(), i.first) - cval.begin();
    int r = lower_bound(cval.begin(), cval.end(), i.second + 1) - cval.begin();
    cnt[l]++;
    cnt[r]--;
  }
  for (int i = 1; i < 2 * n; i++) {
    cnt[i] += cnt[i - 1];
  }

  vector<ll> ans(n + 1);
  for (int i = 1; i < 2 * n; i++) {
    ans[cnt[i - 1]] += cval[i] - cval[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
