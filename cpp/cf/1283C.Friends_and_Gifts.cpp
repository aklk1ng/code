#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> f(n), in(n), out(n);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    f[i]--;
    if (f[i] != -1) {
      out[i]++;
      in[f[i]]++;
    }
  }
  vector<int> loop;
  for (int i = 0; i < n; i++) {
    if (in[i] == 0 && out[i] == 0) {
      loop.push_back(i);
    }
  }

  if (loop.size() == 1) {
    int idx = loop[0];
    for (int i = 0; i < n; i++) {
      if (in[i] == 0 && i != idx) {
        f[idx] = i;
        out[idx]++;
        in[i]++;
        break;
      }
    }
  } else if (loop.size() > 1) {
    for (int i = 0; i < (int)loop.size(); i++) {
      int cur = loop[i];
      int nxt = loop[(i + 1) % (int)loop.size()];
      f[cur] = nxt;
      out[cur]++;
      in[nxt]++;
    }
  }
  loop.clear();
  vector<int> ins, outs;
  for (int i = 0; i < n; i++) {
    if (in[i] == 0) {
      ins.push_back(i);
    }
    if (out[i] == 0) {
      outs.push_back(i);
    }
  }
  for (int i = 0; i < (int)outs.size(); i++) {
    f[outs[i]] = ins[i];
  }

  for (int i = 0; i < n; i++) {
    cout << f[i] + 1 << " \n"[i == n - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
