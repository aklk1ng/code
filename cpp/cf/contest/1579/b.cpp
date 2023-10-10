#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> v;
  for (int i = 0; i < n - 1; i++) {
    int pos = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[pos]) {
        pos = j;
      }
    }
    if (pos > i) {
      v.push_back({i, pos});
      int tmp = a[pos];
      for (int j = pos; j > i; j--) {
        a[j] = a[j - 1];
      }
      a[i] = tmp;
    }
  }
  cout << (int)v.size() << '\n';
  for (auto &[k, v] : v) {
    cout << k + 1 << ' ' << v + 1 << ' ' << v - k << '\n';
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
