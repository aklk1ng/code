#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int x;
  cin >> x;
  if (x >= 1900) {
    cout << "Division 1\n";
  } else if (x >= 1600) {
    cout << "Division 2\n";
  } else if (x >= 1400) {
    cout << "Division 3\n";
  } else {
    cout << "Division 4\n";
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
