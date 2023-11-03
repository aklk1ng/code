#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string s;
  cin >> s;
  int cnt = 0;
  int n = s.size();
  int l = 0, r = n - 1;
  int pos = 0;
  while (l <= r) {
    if (s[l++] != s[r--]) {
      cnt++;
      pos = l;
    }
  }
  if (cnt > 1) {
    cout << "No\n";
  } else if (cnt == 1) {
    cout << "Yes\n";
  } else {
    if (n % 2) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
