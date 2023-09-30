#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  if (s1 == s2) {
    cout << -1 << '\n';
  } else {
    cout << max(s1.size(), s2.size()) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
