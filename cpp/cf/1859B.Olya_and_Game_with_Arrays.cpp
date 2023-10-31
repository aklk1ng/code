#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;

  int mi = INF;
  vector<int> min2;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<int> v(m);
    for (int j = 0; j < m; j++) {
      cin >> v[j];
    }
    int mine = *min_element(v.begin(), v.end());
    mi = min(mi, mine);
    v.erase(find(v.begin(), v.end(), mine));
    min2.push_back(*min_element(v.begin(), v.end()));
  }

  cout << mi + (ll)accumulate(min2.begin(), min2.end(), 0LL) -
              *min_element(min2.begin(), min2.end())
       << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
