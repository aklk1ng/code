#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  set<int> pos;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      pos.insert(i);
    }
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int v;
      cin >> v;
      int num = pos.size();
      if ((v - num) & 1) {
        if (num == 0) {
          cout << "No\n";
        } else {
          int s1 = 2 * *pos.rbegin() - (num - 1);
          int s2 = 2 * (n - *pos.begin() - 1) - (num - 1);
          if (v <= max(s1, s2)) {
            cout << "Yes\n";
          } else {
            cout << "No\n";
          }
        }
      } else {
        if (v <= 2 * n - num) {
          cout << "Yes\n";
        } else {
          cout << "No\n";
        }
      }
    } else {
      int i;
      cin >> i;
      i--;
      pos.erase(i);
      cin >> a[i];
      if (a[i] == 1) {
        pos.insert(i);
      }
    }
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
