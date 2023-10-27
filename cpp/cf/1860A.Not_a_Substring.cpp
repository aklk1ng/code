#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  string a, b;
  int n = s.size();
  for (int i = 0; i < 2 * n; i++) {
    a += "()"[i & 1];
    b += ")("[i < n];
  }

  if (a.find(s) == string::npos) {
    cout << "Yes\n";
    cout << a << '\n';
  } else if (b.find(s) == string::npos) {
    cout << "Yes\n";
    cout << b << '\n';
  } else {
    cout << "No\n";
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
