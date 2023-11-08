#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  if (equal(a.begin() + 1, a.end(), a.begin())) {
    cout << -1 << '\n';
  } else {
    sort(a.begin(), a.end());
    for (auto &e : a) {
      cout << e << " \n"[e == a.back()];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
