#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, b, a;
  cin >> n >> b >> a;
  vector<int> s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  int ans = 1;
  int tmp = a;
  while ((b || a) && ans <= n) {
    if (s[ans]) {
      if (a == tmp || !b) {
        a--;
      } else if (b) {
        b--;
        a = a + 1 >= tmp ? tmp : a + 1;
      }
    } else {
      if (a) {
        a--;
      } else {
        b--;
      }
    }
    ans++;
  }

  cout << ans - 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
