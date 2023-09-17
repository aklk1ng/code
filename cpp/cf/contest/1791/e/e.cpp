#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int negs = 0;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      negs++;
      a[i] = -a[i];
    }
    sum += a[i];
  }
  sort(a.begin(), a.end());
  if (negs & 1) {
    sum -= 2 * a[0];
  }
  cout << sum << '\n';
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
