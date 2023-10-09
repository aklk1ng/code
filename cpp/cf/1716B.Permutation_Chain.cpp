#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = i + 1;
  }
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    for (auto &i : p) {
      cout << i << " \n"[i == p.back()];
    }
    if (i < n - 1) {
      swap(p[i], p[i + 1]);
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
