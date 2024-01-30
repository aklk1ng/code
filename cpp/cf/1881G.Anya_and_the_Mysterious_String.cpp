#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 2e5 + 5;
const int L = 26;

int n, m;
std::string s;
std::set<int> s1, s2;
std::vector<int> f(N);
void add(int i, int x) {
  x = (x % L + L) % L;
  for (; i < n; i |= (i + 1)) {
    f[i] = (f[i] + x) % L;
  }
}

int get(int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res = (res + f[i]) % L;
  }
  return res;
}

void relax(int l, int r) {
  l = std::max(l, 0);
  r = std::min(r, n);
  for (int i = l; i + 1 < r; i++) {
    int c1 = get(i);
    int c2 = get(i + 1);

    if (c1 == c2) {
      s1.insert(i);
    } else {
      s1.erase(i);
    }

    if (i + 2 >= r) {
      continue;
    }
    int c3 = get(i + 2);
    if (c1 == c3) {
      s2.insert(i);
    } else {
      s2.erase(i);
    }
  }
}

void build() {
  s1.clear();
  s2.clear();
  f.assign(n, 0);
  add(0, s[0] - 'a');
  for (int i = 1; i < n; i++) {
    add(i, s[i] - s[i - 1] + L);
  }
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == s[i + 1]) {
      s1.insert(i);
    }
    if (i + 2 < n && s[i] == s[i + 2]) {
      s2.insert(i);
    }
  }
}

void update(int l, int r, int x) {
  add(l, x);
  relax(l - 5, l + 5);
  add(r, L - x);
  relax(r - 5, r + 5);
}

bool query(int l, int r) {
  auto it = s1.lower_bound(l);
  if (it != s1.end() && *it + 1 < r) {
    return false;
  }
  it = s2.lower_bound(l);
  if (it != s2.end() && *it + 2 < r) {
    return false;
  }
  return true;
}

void solve() {
  std::cin >> n >> m >> s;
  build();
  while (m--) {
    int tp, l, r;
    std::cin >> tp >> l >> r;
    l--;
    if (tp == 1) {
      int x;
      std::cin >> x;
      update(l, r, x);
    } else {
      std::cout << (query(l, r) ? "YES" : "NO") << '\n';
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
