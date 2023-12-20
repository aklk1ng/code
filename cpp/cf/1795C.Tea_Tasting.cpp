#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<ll> sum(n + 1);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + b[i];
  }
  vector<ll> cnt(n + 1), add(n + 1);
  for (int i = 0; i < n; i++) {
    int j = upper_bound(sum.begin(), sum.end(), a[i] + sum[i]) - sum.begin() - 1;
    cnt[i]++;
    cnt[j]--;
    add[j] += a[i] - sum[j] + sum[i];
  }
  for (int i = 0; i < n; i++) {
    cout << cnt[i] * b[i] + add[i] << ' ';
    cnt[i + 1] += cnt[i];
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
