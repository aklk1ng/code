#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> a(k), b(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < k; i++) {
    cin >> b[i];
    b[i]--;
  }
  int q;
  cin >> q;
  vector<int> cnt(n + 1);
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    cnt[x - 1]++;
  }
  string ans = "";
  for (int i = 0; i < k; i++) {
    string s1 = s.substr(a[i], b[i] - a[i] + 1);
    int sum = 0;
    int l = a[i], r = b[i];
    for (int j = l; j <= (l + r) / 2; j++) {
      sum += cnt[j] + cnt[r - j + l];
      if (sum & 1) {
        swap(s1[j - l], s1[r - j]);
      }
    }
    ans += s1;
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
