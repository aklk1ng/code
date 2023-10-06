#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, l, r, k;
  cin >> n >> l >> r >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i] >= l) {
      int j = i;
      while (j < n && a[j] <= r && k >= a[j]) {
        k -= a[j++];
      }
      cout << j - i << '\n';
      return;
    }
  }
  cout << 0 << '\n';
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
