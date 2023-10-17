#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << -1 << '\n';
    return;
  }
  vector<int> v;
  int f = 0;
  for (int i = 29; i >= 1; i--) {
    if ((n >> i) & 1) {
      f = 2;
      v.push_back(2);
    } else if (f) {
      v.push_back(1);
    }
  }
  cout << (int)v.size() << '\n';
  for (int &i : v) {
    cout << i << ' ';
  }
  cout << '\n';
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
