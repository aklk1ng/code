#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 10;
#define ll long long
const int N = 2e5 + 10;

void solve() {
  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  while (t--) {
    int i = 0;
    while (i < n - 1)
      if (s[i] == 'B' && s[i + 1] == 'G') {
        swap(s[i], s[i + 1]);
        i += 2;
      } else {
        i++;
      }
  }
  cout << s << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
