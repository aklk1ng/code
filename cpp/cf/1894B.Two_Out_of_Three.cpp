#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> b(n, 1);
  vector inds(101, vector<int>());
  for (int i = 0; i < n; i++) {
    inds[a[i]].push_back(i);
  }

  int k = 2;
  for (int i = 1; i <= 100; i++) {
    if ((int)inds[i].size() >= 2) {
      b[inds[i][0]] = k;
      k++;
      if (k > 3) {
        break;
      }
    }
  }

  if (k <= 3) {
    cout << -1 << '\n';
  } else {
    for (int i = 0; i < n; i++) {
      cout << b[i] << " \n"[i == n - 1];
    }
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
