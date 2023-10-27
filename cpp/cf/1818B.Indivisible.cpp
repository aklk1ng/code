#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
  } else if (n % 2) {
    cout << -1 << '\n';
  } else {
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    for (int i = 0; i < n; i += 2) {
      swap(a[i], a[i + 1]);
    }
    for (auto &e : a) {
      cout << e << " \n"[e == a.back()];
    }
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
