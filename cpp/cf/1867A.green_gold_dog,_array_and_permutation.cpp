#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<pair<ll, int>> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i].first = x;
    a[i].second = i;
  }
  vector<int> ans(n);
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    ans[a[i].second] = i + 1;
  }
  for (int &i : ans) {
    cout << i << " \n"[i == ans.back()];
  }
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
