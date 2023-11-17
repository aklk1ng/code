#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (n == 1 || (n == 2 && a[0] == a[1])) {
    cout << -1 << '\n';
  } else {
    cout << 1 << '\n';
    int pos = find(a.begin(), a.end(), *min_element(a.begin(), a.end())) - a.begin();
    cout << pos + 1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
