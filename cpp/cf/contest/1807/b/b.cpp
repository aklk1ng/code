#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 110;

int a[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int suma = 0, sumb = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] % 2) {
      sumb += a[i];
    } else {
      suma += a[i];
    }
  }
  suma > sumb ? cout << "Yes\n" : cout << "No\n";
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
