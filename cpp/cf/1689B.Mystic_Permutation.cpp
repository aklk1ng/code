#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = i + 1;
  }
  if (n == 1) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == b[i]) {
      swap(b[i], b[i + 1]);
    }
  }
  if (a[n - 1] == b[n - 1]) {
    swap(b[n - 2], b[n - 1]);
  }
  for (int &i : b) {
    cout << i << " \n"[i == b.back()];
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
