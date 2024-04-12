#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;
const int INF = 1e9;

namespace SuffixArray {
std::string s;
std::vector<std::array<int, 2>> classes;

std::vector<int> build(const std::string &bs) {
  s = bs;
  s += '$';

  std::vector<int> c(s.begin(), s.end()), ord(s.size());
  std::iota(ord.begin(), ord.end(), 0);
  classes.resize(s.size());

  for (int j = 1; j < 2 * s.size(); j <<= 1) {
    int hlf = j >> 1;
    for (int i = 0; i < s.size(); i++) {
      classes[i] = {c[i], c[(i + hlf) % s.size()]};
    }
    std::sort(ord.begin(), ord.end(),
              [&](int lhs, int ohs) { return classes[lhs] < classes[ohs]; });
    c[ord[0]] = 0;
    for (int i = 1; i < ord.size(); i++) {
      c[ord[i]] = c[ord[i - 1]] + (classes[ord[i - 1]] != classes[ord[i]]);
    }
  }
  c.pop_back();
  for (auto &e : c) {
    e--;
  }
  return c;
}
}; // namespace SuffixArray

void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k;
  std::cin >> s;

  auto add = [&](int a, int b) {
    a += b;
    if (a >= mod) {
      a -= mod;
    }
    return a;
  };
  auto mul = [&](int a, int b) { return int(a * 1LL * b % mod); };
  auto zero = [&](std::string t) {
    int rem = k, pos = 0;
    for (int i = t.size() - 1; rem > 0 && i >= 0; i--) {
      if (s[i] == '1') {
        continue;
      }
      while (pos < t.size() && s[pos] == '0') {
        pos++;
      }
      if (pos >= i) {
        break;
      }
      std::swap(t[pos], t[i]);
      rem--;
    }
    return t.substr(t.find('1'));
  };
  auto one = [&](std::string t) {
    std::reverse(t.begin(), t.end());
    auto c = SuffixArray::build(s);
    int cntOnes = std::count(t.begin(), t.end(), '1');
    std::array<int, 3> mi = {2 * (int)t.size(), INF, -1};

    int u = 0, cur = 0;
    for (int i = 0; i < n; i++) {
      while (u < t.size() && (u - i < cntOnes || cntOnes - cur > k - 1)) {
        cur += s[u] == '1';
        u++;
      }
      if (u - i < cntOnes || cntOnes - cur > k - 1) {
        break;
      }

      std::array<int, 3> v = {u - i, c[i], i};
      mi = std::min(mi, v);
      cur -= s[i] == '1';
    }

    std::string res = t.substr(mi[2], mi[0]);
    int to = cntOnes - std::count(res.begin(), res.end(), '1');
    for (int i = res.size() - 1; to > 0 && i >= 0; i--) {
      if (res[i] == '0') {
        res[i] = '1';
        to--;
      }
    }
    return res;
  };
  auto s1 = zero(s);
  auto s2 = one(s);

  if (s1.size() > s2.size() || (s1.size() == s2.size() && s1 > s2)) {
    std::swap(s1, s2);
  }

  int ans = 0;
  for (auto &e : s1) {
    ans = add(mul(ans, 2), e - '0');
  }
  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
