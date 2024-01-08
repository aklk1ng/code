#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 5e3 + 5;
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int n;
vector<ll> r(N), hsh(N);
ll tot;
vector<string> s(N);
vector<pair<int, int>> ans;
vector<bool> done(N);

bool solve(vector<int> &t) {
  int pr = -1, pl = -1;
  vector<int> lf, rf;
  for (int &i : t) {
    if (s[i][i] == '0' || done[i] || hsh[i] == tot) {
      continue;
    }
    rf.clear();
    for (int &j : t) {
      if (s[j][i] == '0') {
        lf.push_back(j);
      } else {
        rf.push_back(j);
      }
    }
    if (!lf.empty()) {
      pr = i;
      break;
    }
  }
  if (pr == -1) {
    vector<int> dv, zero, one;
    for (int &i : t) {
      if (done[i]) {
        dv.push_back(i);
      } else if (s[i][i] == '0') {
        zero.push_back(i);
      } else {
        one.push_back(i);
      }
    }
    for (int i = 1; i < (int)dv.size(); i++) {
      ans.push_back({dv[i - 1], dv[i]});
    }
    if (one.empty() && zero.empty()) {
      return 1;
    }
    if (one.size() >= zero.size()) {
      return 0;
    }
    if (one.empty()) {
      if (zero.size() >= 2 || !dv.empty()) {
        return 0;
      }
      return 1;
    }
    for (int i = 0; i < (int)one.size(); i++) {
      ans.push_back({zero[i], one[i]});
      ans.push_back({one[i], zero[i + 1]});
    }
    for (int i = one.size() + 1; i < (int)zero.size(); i++) {
      ans.push_back({one[0], zero[i]});
    }
    if (!dv.empty()) {
      ans.push_back({one[0], dv[0]});
    }
    return 1;
  }
  for (int &i : lf) {
    if (s[i][i] == '0' || done[i] || (hsh[i] ^ hsh[pr]) != tot) {
      continue;
    }
    vector<int> tt;
    for (int &j : t) {
      if (s[j][i] == '0') {
        tt.push_back(j);
      }
    }
    if (tt == rf) {
      pl = i;
      break;
    }
  }
  if (pl == -1) {
    return 0;
  }
  for (int &i : lf) {
    for (int &j : rf) {
      if (j == pr) {
        continue;
      }
      if (s[i][j] != s[pr][j]) {
        return 0;
      }
    }
  }
  for (int &i : rf) {
    for (int &j : lf) {
      if (j == pl) {
        continue;
      }
      if (s[i][j] != s[pl][j]) {
        return 0;
      }
    }
  }
  ans.push_back({pl, pr});
  done[pl] = done[pr] = 1;
  return solve(lf) && solve(rf);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    r[i] = rnd();
    tot ^= r[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '1') {
        hsh[j] ^= r[i];
      }
    }
  }
  bool pos = 1;
  for (int i = 0; i < n; i++) {
    if (s[i][i] == '1') {
      continue;
    }
    for (int j = 0; j < n; j++) {
      if (s[j][i] == '1') {
        pos = 0;
        break;
      }
    }
  }
  if (!pos) {
    cout << "No\n";
    return 0;
  }
  vector<int> v(n);
  iota(v.begin(), v.end(), 0);
  if (!solve(v)) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  for (auto &[k, e] : ans) {
    cout << k + 1 << ' ' << e + 1 << '\n';
  }

  return 0;
}
