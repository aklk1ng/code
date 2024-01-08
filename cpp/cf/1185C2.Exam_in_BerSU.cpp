#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  int sum = 0;
  vector<int> t(n), cnt(101);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n ; i++) {
    int d = sum + t[i] - m, k = 0;
    if (d > 0) {
      for (int j = 100; j > 0; j--) {
        int x = j * cnt[j];
        if (d <= x) {
          k += (d + j - 1) / j;
          break;
        }
        k += cnt[j];
        d -= x;
      }
    }
    sum += t[i];
    cnt[t[i]]++;
    cout << k << ' ';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
