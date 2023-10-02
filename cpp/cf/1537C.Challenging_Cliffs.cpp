#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  sort(h.begin(), h.end());
  if (n == 2) {
    cout << h[0] << ' ' << h[1] << '\n';
    return;
  }
  int pos = -1, mi = INT_MAX;
  for (int i = 1; i < n; i++) {
    if (mi > abs(h[i] - h[i - 1])) {
      pos = i;
      mi = abs(h[i] - h[i - 1]);
    }
  }
  for (int i = pos; i < n; i++) {
    cout << h[i] << ' ';
  }
  for (int i = 0; i < pos; i++) {
    cout << h[i] << " \n"[i == pos - 1];
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
