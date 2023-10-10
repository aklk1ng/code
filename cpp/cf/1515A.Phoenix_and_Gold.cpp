#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> w(n);
  vector<int> suff(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    suff[i] = (i == 0 ? w[i] : suff[i - 1] + w[i]);
  }
  if (suff[n - 1] == x) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
      if (suff[i] == x) {
        swap(w[i], w[i + 1]);
      }
    }
    for (auto &i : w) {
      cout << i << " \n"[i == w.back()];
    }
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
