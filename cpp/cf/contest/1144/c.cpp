#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(2e5 + 5);
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
    m[x]++;
  }
  for (auto &[k, v] : m) {
    if (v > 2) {
      cout << "No\n";
      return;
    }
  }
  vector<int> inc;
  vector<int> dec;
  for (int i = 0; i < 2e5 + 5; i++) {
    if (a[i]) {
      inc.push_back(i);
      a[i]--;
    }
  }
  for (int i = 2e5 + 4; i >= 0; i--) {
    if (a[i]) {
      dec.push_back(i);
      a[i]--;
    }
  }

  cout << "Yes\n";
  int incn = inc.size();
  int decn = dec.size();
  cout << incn << '\n';
  for (int i = 0; i < incn; i++) {
    cout << inc[i] << ' ';
  }
  cout << '\n';

  cout << decn << '\n';
  for (int i = 0; i < decn; i++) {
    cout << dec[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
