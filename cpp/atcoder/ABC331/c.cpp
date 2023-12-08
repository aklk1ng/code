#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, vector<int>> m;
  for (int i = 0; i < n; i++) {
    m[a[i]].push_back(i);
  }
  ll sum = accumulate(a.begin(), a.end(), 0LL);
  vector<ll> ans(n);
  for (auto &[k, v] : m) {
    sum -= 1LL * k * (int)v.size();
    for (auto &e : v) {
      ans[e] = sum;
    }
  }
  for (auto &e : ans) {
    cout << e << " \n"[e == ans.back()];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
