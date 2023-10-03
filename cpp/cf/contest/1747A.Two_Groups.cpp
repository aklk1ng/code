#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  ll sum1 = 0, sum2 = 0;
  ll x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x >= 0) {
      sum1 += x;
    } else {
      sum2 += x;
    }
  }
  cout << abs(abs(sum1) - abs(sum2)) << '\n';
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
