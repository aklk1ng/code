#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  set<int> s;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s.insert(x);
  }
  if (s.size() > k) {
    cout << -1 << '\n';
    return;
  }

  cout << n * k << '\n';
  for (int i = 0; i < n; i++) {
    for (auto &i : s) {
      cout << i << ' ';
    }
    for (int i = 0; i < k - (int)s.size(); i++) {
      cout << 1 << ' ';
    }
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
