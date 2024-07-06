#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int prelen = 1;
  while (prelen < n && a[prelen] <= a[prelen + 1]) {
    prelen++;
  }

  int sufflen = 1;
  while (sufflen < n && a[n - sufflen] >= a[n - sufflen + 1]) {
    sufflen++;
  }

  if (prelen + sufflen >= n) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
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
