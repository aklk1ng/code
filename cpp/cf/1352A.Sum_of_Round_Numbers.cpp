#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  int cnt = 0;
  int x;
  vector<int> a;
  while (n) {
    x = n % 10;
    if (x) {
      ans++;
      a.push_back(x * (int)pow(10, cnt));
    }
    cnt++;
    n /= 10;
  }
  cout << ans << '\n';
  for (int &i : a) {
    cout << i << ' ';
  }
  cout << '\n';
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
