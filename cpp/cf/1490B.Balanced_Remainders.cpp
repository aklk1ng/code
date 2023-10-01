#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> cnt(3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      if (a[j] % 3 == i) {
        cnt[i]++;
      }
    }
  }
  int ans = 0;
  while (*min_element(cnt.begin(), cnt.end()) != n / 3) {
    for (int i = 0; i < 3; i++) {
      if (cnt[i] > n / 3) {
        ans++;
        cnt[i]--;
        cnt[(i + 1) % 3]++;
      }
    }
  }
  cout << ans << '\n';
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
