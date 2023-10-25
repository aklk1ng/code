#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  vector<int> p(n);
  p[0] = a[0];
  for (int i = 1; i < n - 1; i++) {
    if (a[i] == p[i - 1]) {
      p[i] = b[i];
    } else {
      p[i] = a[i];
    }
  }
  if (a[n - 1] != p[0] && a[n - 1] != p[n - 2]) {
    p[n - 1] = a[n - 1];
  } else if (b[n - 1] != p[0] && b[n - 1] != p[n - 2]) {
    p[n - 1] = b[n - 1];
  } else {
    p[n - 1] = c[n - 1];
  }

  for (int i = 0; i < n; i++) {
    cout << p[i] << " \n"[i == n - 1];
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
