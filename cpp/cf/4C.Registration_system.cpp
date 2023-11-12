#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  map<string, int> m;
  while (n--) {
    string s;
    cin >> s;
    if (!m.count(s)) {
      m[s]++;
      cout << "OK\n";
    } else {
      string name = s + to_string(m[s]);
      m[name]++;
      m[s]++;
      cout << name << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
