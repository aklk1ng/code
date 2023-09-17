#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 1e5 + 5;

void solve() {
  string s = "codeforces";
  char c;
  cin >> c;
  int cnt[26]{0};
  for (auto &i : s) {
    cnt[i - 'a']++;
  }
  if (cnt[c - 'a'] != 0) {
    cout << "Yes\n";
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
