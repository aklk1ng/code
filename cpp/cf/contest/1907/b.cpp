#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int ind;
  map<int, char> ma;
  stack<int> lower, upper;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'b') {
      if (!lower.empty()) {
        ind = lower.top();
        ma[ind] = '#';
        lower.pop();
      }
      continue;
    } else if (s[i] == 'B') {
      if (!upper.empty()) {
        ind = upper.top();
        ma[ind] = '#';
        upper.pop();
      }
      continue;
    }
    ma[i] = s[i];
    if (isupper(s[i])) {
      upper.push(i);
    } else {
      lower.push(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (ma.count(i) && ma[i] != '#') {
      cout << ma[i];
    }
  }
  cout << '\n';
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
