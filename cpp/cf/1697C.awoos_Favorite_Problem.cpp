#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  if (count(s.begin(), s.end(), 'b') != count(t.begin(), t.end(), 'b')) {
    cout << "No\n";
    return;
  }
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'b') {
      continue;
    }
    while (t[j] == 'b') {
      j++;
    }
    if (s[i] != t[j] || (s[i] == 'a' && i > j) || (s[i] == 'c' && i < j)) {
      cout << "No\n";
      return;
    }
    j++;
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
