#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

ll query(vector<ll> &t, int node, int ns, int ne, int qs, int qe) {
  if (qe < ns || qs > ne) {
    return -1e15;
  }
  if (qs <= ns && ne <= qe) {
    return t[node];
  }
  int mid = ns + (ne - ns) / 2;
  ll lf = query(t, 2 * node, ns, mid, qs, qe);
  ll rg = query(t, 2 * node + 1, mid + 1, ne, qs, qe);
  return max(lf, rg);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int _n = n;
  while (__builtin_popcount(_n) != 1) {
    _n++;
  }

  vector<ll> pref(n), suf(n);
  pref[0] = a[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }
  suf[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = suf[i + 1] + a[i];
  }

  vector<ll> pret(2 * _n, -1e15), suft(2 * _n, -1e15);
  for (int i = 0; i < n; i++) {
    pret[_n + i] = pref[i];
    suft[_n + i] = suf[i];
  }
  for (int i = _n - 1; i >= 1; i--) {
    pret[i] = max(pret[2 * i], pret[2 * i + 1]);
    suft[i] = max(suft[2 * i], suft[2 * i + 1]);
  }
  auto nextGreater = [&]() {
    stack<int> s;
    vector<int> res(n, n);
    for (int i = 0; i < n; i++) {
      while (!s.empty() && a[s.top()] < a[i]) {
        res[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }
    return res;
  };
  auto preGreater = [&]() {
    stack<int> s;
    vector<int> res(n, -1);
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && a[s.top()] < a[i]) {
        res[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }
    return res;
  };

  vector<int> ng = nextGreater();
  vector<int> pg = preGreater();
  bool ok = true;
  for (int i = 0; i < n; i++) {
    ll r = query(pret, 1, 0, _n - 1, i + 1, ng[i] - 1) - pref[i];
    ll l = query(suft, 1, 0, _n - 1, pg[i] + 1, i - 1) - suf[i];
    if (max(l, r) > 0) {
      ok = false;
      break;
    }
  }

  cout << (ok ? "Yes" : "No") << '\n';
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
