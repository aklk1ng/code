#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll tot = 0;
  vector<ll> v;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      v.push_back((n - 1 - i) - i);
      tot += i;
    } else {
      v.push_back(i - (n - 1 - i));
      tot += n - 1 - i;
    }
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < n; i++) {
    if (v[i] > 0) {
      tot += v[i];
    }
    cout << tot << " \n"[i == n - 1];
  }
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
