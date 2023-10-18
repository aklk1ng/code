#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> ans;
  while (!p.empty()) {
    int sz = p.size();
    int mx = *max_element(p.begin(), p.end());
    for (int i = 0; i < sz; i++) {
      if (p[i] == mx) {
        for (int j = i; j < sz; j++) {
          ans.push_back(p[j]);
          p.erase(p.begin() + i);
        }
        break;
      }
    }
  }
  for (int &e : ans) {
    cout << e << ' ';
  }
  cout << '\n';
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
