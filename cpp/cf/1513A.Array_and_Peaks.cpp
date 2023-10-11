#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int cnt = n;
  for (int i = 2; i < n; i += 2) {
    if (k == 0) {
      break;
    }
    a[i - 1] = cnt--;
    k--;
  }
  if (k) {
    cout << -1 << '\n';
    return;
  }
  int cur = 1;
  for (int i = 0; i < n; i++) {
    if (!a[i]) {
      a[i] = cur++;
    }
  }
  for (int &i : a) {
    cout << i << " \n"[i == a.back()];
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
