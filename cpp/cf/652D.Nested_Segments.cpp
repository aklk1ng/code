#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> leqset;

void solve() {
  int n;
  cin >> n;
  leqset l;
  vector a(n, pair<pair<int, int>, int>());
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    l.insert(a[i].first.second);
  }
  for (int i = 0; i < n; i++) {
    l.erase(a[i].first.second);
    b[a[i].second] = l.order_of_key(a[i].first.second);
  }
  for (int i = 0; i < n; i++) {
    cout << b[i] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
