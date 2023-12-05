#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> s(100);
  set<string> dict;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    dict.insert(s[i]);
  }

  vector<string> l, r;
  string mid;
  for (int i = 0; i < n; i++) {
    string t = s[i];
    reverse(t.begin(), t.end());
    if (t == s[i]) {
      mid = t;
    } else if (dict.find(t) != dict.end()) {
      l.push_back(s[i]);
      r.push_back(t);
      dict.erase(s[i]);
      dict.erase(t);
    }
  }

  cout << (int)l.size() * m * 2 + (int)mid.size() << '\n';
  for (auto &e : l) {
    cout << e;
  }
  cout << mid;
  reverse(r.begin(), r.end());
  for (auto &e : r) {
    cout << e;
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
