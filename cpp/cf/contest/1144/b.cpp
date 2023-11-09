#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] & 1) {
      odd++;
    } else {
      even++;
    }
  }
  if (abs(odd - even) <= 1) {
    cout << 0 << '\n';
  } else {
    sort(a.begin(), a.end());
    int ans = 0;
    int diff = abs(odd - even) - 1;
    if (odd < even) {
      int i = 0;
      while (i < n && diff > 0) {
        if (!(a[i] % 2)) {
          ans += a[i];
          diff--;
        }
        i++;
      }
    } else {
      int i = 0;
      while (i < n && diff > 0) {
        if (a[i] & 1) {
          ans += a[i];
          diff--;
        }
        i++;
      }
    }
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
