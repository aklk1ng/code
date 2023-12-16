#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ifstream f("input.txt");
  string line;
  int ans = 0;
  while (getline(f, line)) {
    int n = line.size();
    for (int i = 0; i < n; i++) {
      string t = line.substr(i, 14);
      set<char> s;
      for (auto &c : t) {
        s.insert(c);
      }
      if ((int)s.size() == 14) {
        ans = i + 14;
        break;
      }
    }
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
