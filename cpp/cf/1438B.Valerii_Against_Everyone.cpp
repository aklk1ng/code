#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x]++;
  }
  for (auto &[k, v] : m) {
    if (v != 1) {
      cout << "Yes\n";
      return;
    }
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
