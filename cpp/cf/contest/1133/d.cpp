#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  auto cal = [&](pair<int, int> &p) {
    if (p.first < 0) {
      p.first *= -1;
      p.second *= -1;
    } else if (p.first == 0 && p.second < 0) {
      p.second *= -1;
    }
    int d = __gcd(p.first, p.second);
    p.first /= d;
    p.second /= d;
  };
  int ans = 0, cnt0 = 0;
  map<pair<int, int>, int> m;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      if (b[i] == 0) {
        cnt0++;
      }
    } else {
      pair<int, int> p = make_pair(-b[i], a[i]);
      cal(p);
      m[p]++;
      ans = max(ans, m[p]);
    }
  }
  cout << cnt0 + ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
