#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<char> odd, even;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      even.push_back(s[i]);
    } else {
      odd.push_back(s[i]);
    }
  }
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());
  string ans = "";
  for (int i = 0, j = 0; i < int(even.size()) || j < int(odd.size()); i++, j++) {
    if (i < int(even.size())) {
      ans += even[i];
    }
    if (j < int(odd.size())) {
      ans += odd[j];
    }
  }

  if (k % 2 == 0) {
    sort(s.begin(), s.end());
    cout << s << '\n';
    return;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
