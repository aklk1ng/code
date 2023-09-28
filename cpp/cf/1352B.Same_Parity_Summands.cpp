#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  int n1 = n - (k - 1);
  if (n1 > 0 && n1 % 2) {
    cout << "Yes\n";
    for (int i = 0; i < k - 1; i++) {
      cout << "1 ";
    }
    cout << n1 << '\n';
    return;
  }
  int n2 = n - 2 * (k - 1);
  if (n2 > 0 && n2 % 2 == 0) {
    cout << "Yes\n";
    for (int i = 0; i < k - 1; i++) {
      cout << "2 ";
    }
    cout << n2 << '\n';
    return;
  }
  cout << "No\n";
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
