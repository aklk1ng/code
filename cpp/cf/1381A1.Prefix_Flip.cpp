#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  vector<int> op;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if (i > 0) {
        op.push_back(i + 1);
      }
      op.push_back(1);
      if (i > 0) {
        op.push_back(i + 1);
      }
    }
  }

  cout << (int)op.size() << ' ';
  for (auto &e : op) {
    cout << e << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
