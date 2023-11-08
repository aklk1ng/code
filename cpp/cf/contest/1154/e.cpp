#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.rbegin(), a.rend());
  queue<int> q;
  for (int i = 0; i < n; i++) {
    q.push(a[i].second);
  }
  set<int> idx;
  for (int i = 0; i < n; i++) {
    idx.insert(i);
  }

  string ans(n, '0');
  int cur = 0;
  while (!idx.empty()) {
    while (!idx.count(q.front())) {
      q.pop();
    }
    int pos = q.front();
    q.pop();

    vector<int> add;
    auto it = idx.find(pos);
    for (int i = 0; i <= k; i++) {
      add.push_back(*it);
      if (it == idx.begin()) {
        break;
      }
      it--;
    }
    it = next(idx.find(pos));
    for (int i = 0; i < k; i++) {
      if (it == idx.end()) {
        break;
      }
      add.push_back(*it);
      it++;
    }
    for (auto &e : add) {
      idx.erase(e);
      ans[e] = '1' + cur;
    }
    cur ^= 1;
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
