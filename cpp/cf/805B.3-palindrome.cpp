#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s = "abba";
  int cnt = n / 4;
  n %= 4;
  for (int i = 0; i < cnt; i++) {
    cout << s;
  }
  for (int i = 0; i < n; i++) {
    cout << s[i];
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
