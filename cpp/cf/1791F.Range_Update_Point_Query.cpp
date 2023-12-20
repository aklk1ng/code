#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  set<int> s;

  auto digit_sum = [&](int x) {
    int res = 0;
    while (x) {
      res += x % 10;
      x /= 10;
    }
    return res;
  };
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 9) {
      s.insert(i);
    }
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int lst = l;
      while (!s.empty()) {
        auto it = s.lower_bound(lst);
        if (it == s.end() || *it > r) {
          break;
        }
        a[*it] = digit_sum(a[*it]);
        int t = *it;
        s.erase(it);
        if (a[t] > 9) {
          s.insert(t);
        }
        lst = t + 1;
      }
    } else {
      int x;
      cin >> x;
      x--;
      cout << a[x] << '\n';
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
