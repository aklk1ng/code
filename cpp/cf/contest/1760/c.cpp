#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> v(s);
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (s[i] != v.back()) {
      cout << s[i] - v.back() << ' ';
    } else {
      cout << s[i] - v[n - 2] << ' ';
    }
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
