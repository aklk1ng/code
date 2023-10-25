#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mx = find(a.begin(), a.end(), *max_element(a.begin(), a.end())) - a.begin();
  int mi = find(a.begin(), a.end(), *min_element(a.begin(), a.end())) - a.begin();
  cout << max({mi, mx, n - 1 - mi, n - 1 - mx}) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
