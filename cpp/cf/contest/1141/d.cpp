#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  string l;
  cin >> l;
  vector<vector<int>> left(26);
  vector<int> wl;
  for (int i = 0; i < n; i++) {
    if (l[i] != '?') {
      left[l[i] - 'a'].push_back(i);
    } else {
      wl.push_back(i);
    }
  }
  string r;
  cin >> r;
  vector<vector<int>> right(26);
  vector<int> wr;
  for (int i = 0; i < n; i++) {
    if (r[i] != '?') {
      right[r[i] - 'a'].push_back(i);
    } else {
      wr.push_back(i);
    }
  }

  vector<pair<int, int>> p;
  vector<int> cl(26), cr(26);
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < min((int)left[i].size(), (int)right[i].size()); j++) {
      p.push_back(make_pair((int)left[i][j] + 1, (int)right[i][j] + 1));
    }
    cl[i] = cr[i] = min((int)left[i].size(), (int)right[i].size());
  }
  for (int i = 0; i < 26; i++) {
    while (cl[i] < (int)left[i].size() && !wr.empty()) {
      p.push_back(make_pair((int)left[i][cl[i]] + 1, wr[(int)wr.size() - 1] + 1));
      cl[i]++;
      wr.pop_back();
    }
  }
  for (int i = 0; i < 26; i++) {
    while (cr[i] < (int)right[i].size() && !wl.empty()) {
      p.push_back(make_pair(wl[(int)wl.size() - 1] + 1, (int)right[i][cr[i]] + 1));
      cr[i]++;
      wl.pop_back();
    }
  }

  for (int i = 0; i < min((int)wl.size(), (int)wr.size()); i++) {
    p.push_back(make_pair(wl[i] + 1, wr[i] + 1));
  }

  cout << (int)p.size() << '\n';
  for (auto &e : p) {
    cout << e.first << ' ' << e.second << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
