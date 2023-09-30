#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

int bit(int x) {
  int res = 0;
  while (x) {
    x /= 10;
    res++;
  }
  return res;
}

void solve() {
  int m;
  cin >> m;
  cout << m - (int)pow(10, bit(m) - 1) << '\n';
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
