#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  int pos = find(p.begin(), p.end(), 1) - p.begin();
  bool okl = true, okr = true;
  for (int i = 1; i < n; i++) {
    okl &= (p[(pos - i + n) % n] == i + 1);
    okr &= (p[(pos + i + n) % n] == i + 1);
  }
  if (okl || okr) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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
