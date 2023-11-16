#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  if ((int)s.size() == 2) {
    cout << n / 2 + 1 << '\n';
  } else {
    cout << n << '\n';
  }
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
