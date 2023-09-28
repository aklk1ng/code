#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int a, b;
  cin >> a >> b;
  if (b == 1) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    cout << a << ' ' << a * 1LL * b << ' ' << a * 1LL * (b + 1) << '\n';
  }
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
