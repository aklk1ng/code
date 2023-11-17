#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> pos, neg, a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > 0) {
      pos.push_back(x);
    } else if (x < 0) {
      neg.push_back(x);
    } else {
      if ((int)a.size() < 2) {
        a.push_back(x);
      }
    }
  }

  if ((int)pos.size() > 2 || (int)neg.size() > 2) {
    cout << "No\n";
    return;
  }
  for (int &e : pos) {
    a.push_back(e);
  }
  for (int &e : neg) {
    a.push_back(e);
  }
  int sz = a.size();
  for (int i = 0; i < sz; i++) {
    for (int j = i + 1; j < sz; j++) {
      for (int k = j + 1; k < sz; k++) {
        bool ok = false;
        for (int l = 0; l < sz; l++) {
          if (a[i] + a[j] + a[k] == a[l]) {
            ok = true;
          }
        }
        if (!ok) {
          cout << "No\n";
          return;
        }
      }
    }
  }
  cout << "Yes\n";
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
