#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

struct man {
  int h, w, id;
};

bool operator<(const man &a, const man &b) { return tie(a.h, a.w, a.id) < tie(b.h, b.w, b.id); }

struct my_min {
  pair<int, int> mi1, mi2;
};

void solve() {
  int n;
  cin >> n;
  vector<man> hor, ver;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int h, w;
    cin >> h >> w;
    hor.push_back({h, w, i});
    ver.push_back({w, h, i});
    a.emplace_back(h, w);
  }
  sort(hor.begin(), hor.end());
  sort(ver.begin(), ver.end());

  auto get = [&](const vector<man> &t) {
    vector<pair<int, my_min>> res;
    my_min cur{pair<int, int>(INT_MAX, -1), pair<int, int>(INT_MAX, -1)};
    for (auto &e : t) {
      if (e.w < cur.mi1.first) {
        cur.mi2 = cur.mi1;
        cur.mi1 = pair<int, int>(e.w, e.id);
      } else {
        cur.mi2 = min(cur.mi2, pair<int, int>(e.w, e.id));
      }
      res.emplace_back(e.h, cur);
    }
    return res;
  };
  auto cal = [&](const vector<pair<int, my_min>> &mins, int h, int w, int id) {
    int l = -1, r = (int)mins.size();
    while (l + 1 != r) {
      int m = (l + r) / 2;
      if (mins[m].first < h) {
        l = m;
      } else {
        r = m;
      }
    }
    if (l == -1) {
      return -1;
    }

    auto mi1 = mins[l].second.mi1;
    auto mi2 = mins[l].second.mi2;
    if (mi1.second != id) {
      return mi1.first < w ? mi1.second + 1 : -1;
    }
    return mi2.first < w ? mi2.second + 1 : -1;
  };

  auto hormins = get(hor);
  auto vermins = get(ver);

  for (int i = 0; i < n; i++) {
    auto [h, w] = a[i];
    int id = cal(hormins, h, w, i);
    if (id == -1) {
      id = cal(vermins, h, w, i);
    }
    cout << id << " \n"[i == n - 1];
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
