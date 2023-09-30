#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  auto check = [&]() -> bool {
    int diff = INF;
    for (int i = 0; i < n; i++) {
      if (b[i]) {
        diff = min(a[i] - b[i], INF);
      }
    }
    if (diff < 0) {
      return false;
    }
    if (diff == INF) {
      return true;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] - b[i] > diff) {
        return false;
      }
      if (b[i] != 0 && a[i] - b[i] < diff) {
        return false;
      }
    }
    return true;
  };
  cout << (check() ? "Yes\n" : "No\n");
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
