#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b == c) {
    cout << "+\n";
    return;
  } else if (a - b == c) {
    cout << "-\n";
    return;
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
