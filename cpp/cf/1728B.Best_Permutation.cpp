#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  iota(p.begin(), p.end(), 1);
  for (int i = n & 1; i < n - 2; i += 2) {
    swap(p[i], p[i + 1]);
  }
  for (int &x : p) {
    cout << x << " \n"[x == p.back()];
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
