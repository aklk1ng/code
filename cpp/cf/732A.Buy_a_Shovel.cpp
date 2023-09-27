#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int k, r;
  cin >> k >> r;
  for (int i = 1; i <= 10; i++) {
    if ((k * i) % 10 == 0 || (k * i) % 10 == r) {
      cout << i << '\n';
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
