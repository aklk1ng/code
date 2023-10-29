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

  sort(a.begin(), a.end());
  int l = 0, r = n + 1;
  while (l + 1 != r) {
    int m = l + (r - l) / 2;
    bool ok = true;
    if (2 * m + 1 > n) {
      ok = false;
    } else {
      vector<int> b;
      int pa = 0, pb = n - (m + 1);
      for (int i = 0; i < 2 * m + 1; i++) {
        if (i % 2 == 0) {
          b.emplace_back(a[pb]);
          pb++;
        } else {
          b.emplace_back(a[pa]);
          pa++;
        }
      }

      for (int i = 1; i < 2 * m + 1; i += 2) {
        if (b[i] >= b[i - 1] || b[i] >= b[i + 1]) {
          ok = false;
        }
      }
    }

    if (ok) {
      l = m;
    } else {
      r = m;
    }
  }

  cout << l << '\n';
  vector<int> b;
  int pa = 0, pb = n - (l + 1);
  for (int i = 0; i < 2 * l + 1; i++) {
    if (i % 2 == 0) {
      b.emplace_back(a[pb]);
      pb++;
    } else {
      b.emplace_back(a[pa]);
      pa++;
    }
  }
  for (int i = pa; i < n - (l + 1); i++) {
    b.emplace_back(a[i]);
  }

  for (auto &e : b) {
    cout << e << " \n"[e == b.back()];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
