#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string prefix = "abcd";
  int t = n / 4;
  n %= 4;
  string ans = "";
  for (int i = 0; i < t; i++) {
    ans += prefix;
  }
  for (int i = 0; i <= n - 1; i++) {
    ans += prefix[i];
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
