#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (i == 0 || x != a.back()) {
      a.push_back(x);
    }
  }
  int cnt = 0;
  for (int i = 0; i < a.size(); i++) {
    if ((i == 0 || a[i - 1] > a[i]) && (i == a.size() - 1 || a[i] < a[i + 1])) {
      cnt++;
    }
  }
  cout << (cnt == 1 ? "Yes\n" : "No\n");
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
