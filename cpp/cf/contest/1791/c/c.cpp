#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = 0, r = n - 1;

  while (l <= r && (s[l] ^ s[r]) == 1) {
    l++;
    r--;
    n -= 2;
  }
  cout << n << '\n';
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
