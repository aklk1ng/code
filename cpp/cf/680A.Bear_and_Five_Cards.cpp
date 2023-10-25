#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  map<int, int> m;
  vector<int> t(5);
  for (int i = 0; i < 5; i++) {
    cin >> t[i];
    m[t[i]]++;
  }
  int ans = accumulate(t.begin(), t.end(), 0);
  sort(t.rbegin(), t.rend());

  int suf = 0;
  for (int i = 0; i < 5; i++) {
    if (m[t[i]] == 2) {
      suf = max(suf, t[i] * 2);
    } else if (m[t[i]] >= 3) {
      suf = max(suf, t[i] * 3);
    }
  }
  cout << ans - suf << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
