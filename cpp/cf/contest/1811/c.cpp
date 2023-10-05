#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> b[i];
  }
  vector<int> a;
  a.push_back(b[0]);
  for (int i = 1; i < n - 1; i++) {
    a.push_back(min(b[i], b[i - 1]));
  }
  a.push_back(b[n - 2]);
  for (auto &i : a) {
    cout << i << ' ';
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
