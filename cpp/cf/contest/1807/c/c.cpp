#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 110;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sz = s.size();
  if (sz == 1) {
    cout << "Yes\n";
    return;
  }
  map<char, int> cnt;
  for (int i = 0; i < sz; i++) {
    cnt[s[i]]++;
  }
  for (auto &[c, v] : cnt) {
    if (v > 1) {
      int pos = s.find(c);
      for (int i = 0; i < sz; i++) {
        if (s[i] == c && (i % 2 != pos % 2)) {
          cout << "NO\n";
          return;
        }
      }
    }
  }
  cout << "YES\n";
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
