#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 10;
#define ll long long
const int N = 2e5 + 10;

void solve() {
  int n;
  cin >> n;
  string s1, s2, s3;
  cin >> s1;
  cin >> s2;
  cin >> s3;
  if (s1 == s2 && s2 == s3) {
    cout << n;
    return;
  }
  for (int i = 0; i < n; i++) {
    
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // int tt;
  // cin >> tt;
  // while (tt--) {
  //   solve();
  // }
  solve();
  return 0;
}
