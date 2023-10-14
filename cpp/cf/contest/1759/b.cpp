#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int m, s;
  cin >> m >> s;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  s += accumulate(b.begin(), b.end(), 0);
  int sm = 0;
  int cnt = 0;
  for (int i = 1; i <= s; i++) {
    if (sm >= s) {
      break;
    }
    sm += i;
    cnt = i;
  }
  if (sm != s || *max_element(b.begin(), b.end()) > cnt || cnt <= m) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
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
