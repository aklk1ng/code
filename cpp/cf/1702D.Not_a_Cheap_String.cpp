#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  string w;
  cin >> w;
  int p;
  cin >> p;
  int sum = 0;
  string s(w);
  sort(s.rbegin(), s.rend());
  for (char &c : w) {
    sum += (c - 'a' + 1);
  }
  vector<int> cnt(26);
  for (char &c : s) {
    if (sum > p) {
      cnt[c - 'a']++;
      sum -= (c - 'a' + 1);
    }
  }
  for (char &c : w) {
    if (cnt[c - 'a']) {
      cnt[c - 'a']--;
      continue;
    }
    cout << c;
  }
  cout << '\n';
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
