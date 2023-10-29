#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  if (n <= 2) {
    cout << -1 << '\n';
  } else {
    for (int i = n; i > 0; i--) {
      cout << i << " \n"[i == 1];
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
