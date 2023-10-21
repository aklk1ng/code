#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> w(n), h(n);
  int sum = 0, h1 = 0, h2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> h[i];
    sum += w[i];
    if (h[i] > h1) {
      h2 = h1;
      h1 = h[i];
    } else if (h[i] > h2) {
      h2 = h[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (h[i] != h1) {
      cout << (sum - w[i]) * h1 << ' ';
    } else {
      cout << (sum - w[i]) * h2 << ' ';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
