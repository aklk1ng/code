#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 60;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int i = 0;
  while (i < n) {
    int start = i;
    cout << s[i++];
    while (s[i++] != s[start])
      ;
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
