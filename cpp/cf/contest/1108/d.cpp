#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j < n && s[j] == s[i]) {
      j++;
    }
    string t = "RGB";
    t.erase(t.find(s[i]), 1);
    if (j < n) {
      t.erase(t.find(s[j]), 1);
    }
    for (int k = i + 1; k < j; k += 2) {
      ans++;
      s[k] = t[0];
    }
    i = j - 1;
  }
  cout << ans << '\n';
  cout << s << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
