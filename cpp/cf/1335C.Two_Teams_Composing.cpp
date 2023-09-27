#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int mx = *max_element(cnt.begin(), cnt.end());
  int diff = n + 1 - count(cnt.begin(), cnt.end(), 0);
  cout << max(min(mx - 1, diff), min(mx, diff - 1)) << '\n';
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
