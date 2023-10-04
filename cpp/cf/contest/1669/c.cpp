#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  bool even1 = false, old1 = false, even2 = false, old2 = false;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i & 1) {
      if (a[i] % 2 == 1) {
        old1 = true;
      } else {
        even1 = true;
      }
    } else {
      if (a[i] % 2 == 1) {
        old2 = true;
      } else {
        even2 = true;
      }
    }
  }
  if ((even1 && old1) || (even2 && old2)) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
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
