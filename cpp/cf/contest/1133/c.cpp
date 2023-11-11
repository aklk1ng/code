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

  sort(a.begin(), a.end());
  int ans = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    while (j < n && a[j] - a[i] <= 5) {
      j++;
      ans = max(ans, j - i);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
