#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> p({4, 8, 15, 16, 23, 42});
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
  }

  vector<int> cnt(6);
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      cnt[0]++;
    } else {
      if (cnt[a[i] - 1] > 0) {
        cnt[a[i] - 1]--;
        cnt[a[i]]++;
      }
    }
  }
  cout << n - cnt[5] * 6 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
