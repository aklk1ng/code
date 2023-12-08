#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> idx(2e5 + 5);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    idx[x] = i;
  }
  if (idx[n] < min(idx[1], idx[2])) {
    cout << idx[n] << ' ' << min(idx[1], idx[2]) << '\n';
  } else if (idx[n] > max(idx[1], idx[2])) {
    cout << idx[n] << ' ' << max(idx[1], idx[2]) << '\n';
  } else {
    cout << idx[1] << ' ' << idx[2] << '\n';
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
