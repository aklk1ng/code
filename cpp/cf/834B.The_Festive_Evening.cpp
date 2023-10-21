#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<char> s(n);
  map<char, int> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    m[s[i]] = i;
  }

  set<char> cnt;
  for (int i = 0; i < n; i++) {
    cnt.insert(s[i]);
    if ((int)cnt.size() > k) {
      cout << "Yes\n";
      return;
    }
    if (m[s[i]] == i) {
      cnt.erase(s[i]);
    }
  }
  cout << "No\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
