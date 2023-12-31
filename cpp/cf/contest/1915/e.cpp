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
  map<ll, ll> m;
  ll s = 0;
  m[0] = 1;
  for (int i = 0; i < n; i++) {
    a[i] *= i % 2 ? -1 : 1;
    s += a[i];
    if (m[s]) {
      cout << "Yes\n";
      return;
    }
    m[s]++;
  }
  cout << "No\n";
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
