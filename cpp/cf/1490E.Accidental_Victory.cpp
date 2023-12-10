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
  vector<int> b(a);
  sort(b.begin(), b.end());
  auto check = [&](int pos) {
    ll t = b[pos];
    for (int i = 0; i < (int)b.size(); i++) {
      if (i == pos) {
        continue;
      }
      if (t < b[i]) {
        return false;
      }
      t += b[i];
    }
    return true;
  };
  int l = -1, r = n - 1;
  while (l + 1 != r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (a[i] >= b[r]) {
      res.push_back(i + 1);
    }
  }
  cout << (int)res.size() << '\n';
  for (auto &e : res) {
    cout << e << " \n"[e == res.back()];
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
