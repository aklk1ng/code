#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int k = accumulate(a.begin(), a.end(), 0LL) / n;
  vector<int> b(n), ans(n);
  int l = n - k;
  for (int i = l; i < n; i++) {
    b[i] = n - 1;
  }
  for (int i = n - 1; i >= 0 && l <= i; i--) {
    int cur = a[i] - (b[i] - i);
    if (cur == i + 1) {
      ans[i] = 1;
    } else if (cur == 1) {
      ans[i] = 0;
      l--;
      b[l] = i - 1;
    }
  }
  for (auto &e : ans) {
    cout << e << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (true) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
