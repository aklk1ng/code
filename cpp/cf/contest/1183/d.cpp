#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  sort(a.rbegin(), a.rend());
  int ans = a[0];
  int lst = a[0];
  for (int i = 1; i <= n; i++) {
    if (lst == 0) {
      break;
    }
    if (a[i] >= lst) {
      ans += lst - 1;
      lst -= 1;
    } else {
      ans += a[i];
      lst = a[i];
    }
  }

  cout << ans << '\n';
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
