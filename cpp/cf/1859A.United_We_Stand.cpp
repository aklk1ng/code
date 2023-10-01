#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (a.back() == a.front()) {
    cout << -1 << '\n';
  } else {
    int it = 0;
    while (a.front() == a[it]) {
      it++;
    }
    cout << it << ' ' << n - it << '\n';
    for (int i = 0; i < it; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    for (int i = it; i < n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
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
