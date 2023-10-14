#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> m;
  auto add = [&](int x) {
    for (int i = 2; i <= x / i; i++) {
      while (x % i == 0) {
        m[i]++;
        x /= i;
      }
    }
    if (x > 1) {
      m[x]++;
    }
  };
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    add(a[i]);
  }
  for (auto &[k, v] : m) {
    if (v % n) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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
