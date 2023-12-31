#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  vector<string> s(3);
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (s[i][j] == '?') {
        set<char> v;
        for (int sx = 0; sx < 3; sx++) {
          v.insert(s[sx][j]);
        }
        if (!v.count('A')) {
          cout << "A\n";
        } else if (!v.count('B')) {
          cout << "B\n";
        } else if (!v.count('C')){
          cout << "C\n";
        }
        return;
      }
    }
  }
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
