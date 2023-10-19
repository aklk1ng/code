#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool ans = false;
  if (n == 1) {
    ans = (a[0] == k);
  } else {
    sort(a.begin(), a.end());
    int i = 0, j = 1;
    while (i < n && j < n) {
      if (a[i] + abs(k) == a[j]) {
        ans = true;
        break;
      } else if (a[i] + abs(k) < a[j]) {
        i++;
      } else {
        j++;
      }
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
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
