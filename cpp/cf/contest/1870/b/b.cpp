#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a;
  a.push_back(n + 1);
  a.push_back(n + 2);
  int sum = accumulate(a.begin(), a.end(), 0);
  int l = 0, r = 1;
  for (int i = n + 3; i <= INT_MAX; i++) {
    if ((int)a.size() == n) {
      break;
    }
    if ((3 * i) % sum) {
      a.push_back(i);
    } else {
      continue;
    }
    sum -= a[l];
    l++, r++;
    sum += a[r];
  }
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
