#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, m;
  cin >> n >> m;
  string b(m, 'B');
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (b[min(x - 1, m + 1 - x - 1)] == 'A') {
      b[max(x - 1, m + 1 - x - 1)] = 'A';
    } else {
      b[min(x - 1, m + 1 - x - 1)] = 'A';
    }
  }
  cout << b << '\n';
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
