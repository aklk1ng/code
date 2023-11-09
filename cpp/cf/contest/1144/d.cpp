#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), cnt(2e5 + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  int mx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
  int pos = find(a.begin(), a.end(), mx) - a.begin();

  cout << n - cnt[mx] << '\n';
  for (int i = pos - 1; i >= 0; i--) {
    cout << 1 + (a[i] > a[i + 1]) << ' ' << i + 1 << ' ' << i + 2 << '\n';
    a[i] = a[i + 1];
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] != mx) {
      cout << 1 + (a[i + 1] > a[i]) << ' ' << i + 2 << ' ' << i + 1 << '\n';
      a[i + 1] = a[i];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
