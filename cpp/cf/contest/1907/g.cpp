#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<bool> s(n);
  string ss;
  cin >> ss;
  for (int i = 0; i < n; i++) {
    s[i] = ss[i] == '1';
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  vector<int> res, d(n), z;
  for (int i = 0; i < n; i++) {
    d[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (d[i] == 0) {
      z.push_back(i);
    }
  }
  for (int i = 0; i < (int)z.size(); i++) {
    int x = z[i];
    int y = a[x];
    if (s[x]) {
      res.push_back(x);
      s[x] = !s[x];
      s[y] = !s[y];
    }
    d[y]--;
    if (d[y] == 0) {
      z.push_back(y);
    }
  }

  vector<bool> u(n);
  for (int i = 0; i < n; i++) {
    if (s[i] && !u[i]) {
      int x = i;
      vector<int> p;
      vector<bool> ps;
      int c = 0;
      while (!u[x]) {
        p.push_back(x);
        ps.push_back(s[x]);
        c += s[x];
        u[x] = true;
        x = a[x];
      }
      int k = p.size();
      p.push_back(x);
      ps.push_back(s[x]);
      if (c % 2 == 1) {
        cout << -1 << '\n';
        return;
      }
      vector<int> v1;
      vector<bool> ps1 = ps;
      for (int j = 0; j < k; j++) {
        if (j == 0 || ps1[j]) {
          v1.push_back(p[j]);
          ps1[j] = !ps1[j];
          ps1[j + 1] = !ps1[j + 1];
        }
      }
      vector<int> v2;
      vector<bool> ps2 = ps;
      for (int j = 0; j < k; j++) {
        if (j != 0 && ps2[j]) {
          v2.push_back(p[j]);
          ps2[j] = !ps2[j];
          ps2[j + 1] = !ps2[j + 1];
        }
      }
      if ((int)v1.size() < (int)v2.size()) {
        for (auto &e : v1) {
          res.push_back(e);
        }
      } else {
        for (auto &e : v2) {
          res.push_back(e);
        }
      }
    }
  }

  cout << res.size() << '\n';
  for (auto &e : res) {
    cout << e + 1 << " \n"[e == res.back()];
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
