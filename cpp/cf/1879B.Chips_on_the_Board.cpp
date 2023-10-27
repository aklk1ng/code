#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  ll mia = *min_element(a.begin(), a.end());
  ll suma = accumulate(a.begin(), a.end(), 0LL);
  ll mib = *min_element(b.begin(), b.end());
  ll sumb = accumulate(b.begin(), b.end(), 0LL);
  cout << min(mia * n + sumb, mib * n + suma) << '\n';
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
