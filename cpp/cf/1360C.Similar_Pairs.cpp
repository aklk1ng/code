#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int old = 0, even = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2) {
      old++;
    } else {
      even++;
    }
  }
  if (old % 2 != even % 2) {
    cout << "No\n";
    return;
  } else {
    if (even % 2 == 0) {
      cout << "Yes\n";
      return;
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] % 2 != a[j] % 2 && abs(a[i] - a[j]) == 1) {
          cout << "Yes\n";
          return;
        }
      }
    }
    cout << "No\n";
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
