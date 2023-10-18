#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  vector<int> cnt(26);
  for (auto &i : s) {
    cnt[i - 'a']++;
  }
  if (t != "abc" || !cnt[0] || !cnt[1] || !cnt[2]) {
    cout << s << '\n';
  } else {
    while (cnt[0]--) {
      cout << 'a';
    }
    while (cnt[2]--) {
      cout << 'c';
    }
    while (cnt[1]--) {
      cout << 'b';
    }
    for (int i = 3; i < 26; i++) {
      while (cnt[i]--) {
        cout << char('a' + i);
      }
    }
    cout << '\n';
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
