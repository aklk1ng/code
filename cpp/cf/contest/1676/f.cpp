#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  vector<int> c;
  for (auto &[x, v] : m) {
    if (v >= k) {
      c.push_back(x);
    }
  }
  if (c.size() == 0) {
    cout << -1 << '\n';
    return;
  }
  sort(c.begin(), c.end());
  int mx = 0;
  int lans = c[0], rans = c[0];
  int l = c[0];
  for (int i = 1; i < (int)c.size(); i++) {
    if (c[i] - 1 == c[i - 1]) {
      if (c[i] - l > mx) {
        lans = l;
        rans = c[i];
        mx = c[i] - l;
      }
    } else {
      l = c[i];
    }
  }
  cout << lans << ' ' << rans << '\n';
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
