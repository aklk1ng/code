#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 1; i--) {
    int pre = a[i + 1];
    bool ok = false;
    for (int j = i; j >= 1; j--) {
      ok = a[j] == 0;
      pre -= (a[j] = pre - a[j]);
      if (ok) {
        sort(a.begin() + j, a.begin() + i + 1);
        break;
      }
    }
    if (!ok) {
      sort(a.begin(), a.begin() + i + 1);
    }
  }
  cout << a[1] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (true) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
