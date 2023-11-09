#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] != (*s.begin() + i)) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
