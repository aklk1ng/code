#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int i = 0, j = n - 1;
  while (k--) {
    if (i < n && j < n) {
      if (a[i] < b[j]) {
        swap(a[i], b[j]);
        i++;
        j--;
      } else {
        break;
      }
    }
  }
  cout << accumulate(a.begin(), a.end(), 0) << '\n';
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
