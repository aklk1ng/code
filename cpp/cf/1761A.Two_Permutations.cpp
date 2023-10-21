#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
                  
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a + b + 2 <= n) {
    cout << "Yes\n";
  } else if (a == b && a == n) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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
