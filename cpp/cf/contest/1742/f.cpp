#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int q;
  cin >> q;
  ll cntA = 0, cntB = 0;
  bool otherA = false, otherB = false;
  while (q--) {
    ll d, k;
    string x;
    cin >> d >> k >> x;
    for (auto &c : x) {
      if (d == 1) {
        if (c != 'a') {
          otherA = true;
        } else {
          cntA += k;
        }
      } else {
        if (c != 'a') {
          otherB = true;
        } else {
          cntB += k;
        }
      }
    }
    if (otherB) {
      cout << "Yes\n";
    } else if (!otherA && cntA < cntB) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
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
