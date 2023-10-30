#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  set<int> s;
  vector<int> a(n + 1);
  int tt = n + 1, hh = n + 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (!s.count(x)) {
      s.insert(x);
      a[hh--] = x;
      if ((int)s.size() > k) {
        s.erase(a[tt--]);
      }
    }
  }

  cout << (int)s.size() << '\n';
  for (int i = hh + 1; i <= tt; i++) {
    cout << a[i] << " \n"[i == tt];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
