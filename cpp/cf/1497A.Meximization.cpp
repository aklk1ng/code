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
  vector<int> b;
  for (int i = 0; i < n; i++) {
    if (i == 0 || a[i] != a[i - 1]) {
      b.push_back(a[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0 && a[i] == a[i - 1]) {
      b.push_back(a[i]);
    }
  }
  for (int &e : b) {
    cout << e << ' ';
  }
  cout << '\n';
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
