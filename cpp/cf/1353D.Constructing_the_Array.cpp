#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct cmp {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
    int lena = a.second - a.first + 1;
    int lenb = b.second - b.first + 1;
    if (lena == lenb) {
      return a.first < b.first;
    }
    return lena > lenb;
  }
};

void solve() {
  int n;
  cin >> n;
  set<pair<int, int>, cmp> s;
  s.insert({0, n - 1});
  vector<int> a(n);
  for (int i = 1; i <= n; i++) {
    auto cur = *s.begin();
    s.erase(s.begin());
    int id = (cur.first + cur.second) / 2;
    a[id] = i;
    if (cur.first < id) {
      s.insert({cur.first, id - 1});
    }
    if (id < cur.second) {
      s.insert({id + 1, cur.second});
    }
  }

  for (auto &e : a) {
    cout << e << " \n"[e == a.back()];
  }
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
