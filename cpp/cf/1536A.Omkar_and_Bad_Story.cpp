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
  if (*min_element(a.begin(), a.end()) < 0) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    cout << 101 << '\n';
    for (int i = 0; i <= 100; i++) {
      cout << i << " \n"[i == 100];
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
