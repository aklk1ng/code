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
  int i = 0, j = 0;
  while (i < n) {
    while (i < n && s[i] == 'W') {
      i++;
    }
    if (i == n) {
      cout << "Yes\n";
      return;
    }
    j = i;
    while (j < n && s[j] != 'W') {
      j++;
    }
    bool flag = false;
    for (int k = i; k < j; k++) {
      if (s[k] != s[i]) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      cout << "No\n";
      return;
    }
    while (j < n && s[j] == 'W') {
      j++;
    }
    i = j;
  }
  cout << "Yes\n";
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
