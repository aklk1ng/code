#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> cnt(k);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x % k]++;
  }
  
  int ans = cnt[0] / 2;
  if (k % 2 == 0) {
    ans += cnt[k / 2] / 2;
  }
  for (int i = 1; i < (k + 1) / 2; i++) {
    ans += min(cnt[i], cnt[k - i]);
  }
  cout << ans * 2 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
