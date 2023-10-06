#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (s.find("RL") != string::npos) {
    cout << 0 << '\n';
  } else if (s.find("LR") != string::npos) {
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        if (s[i + 1] == 'R') {
          cout << i + 1 << '\n';
          return;
        }
      }
    }
  } else {
    cout << -1 << '\n';
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
