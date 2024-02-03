#include <bits/stdc++.h>
typedef long long ll;

struct word {
  ll len, cnt;
  std::string s;
};

std::vector<std::string> split(const std::string &s, char p) {
  std::vector<std::string> res(1);
  for (auto &c : s) {
    if (c == p) {
      res.emplace_back();
    } else {
      res.back() += c;
    }
  }
  return res;
}

std::string getfst(std::string s) {
  if ((int)s.size() < 3) {
    return s;
  }
  return s.substr(0, 3);
}

std::string getlst(std::string s) {
  if ((int)s.size() < 3) {
    return s;
  }
  return s.substr(s.size() - 3, 3);
}

int cnt(const std::string &s, const std::string &p) {
  int res = 0;
  for (int i = 0; i + (int)p.size() <= (int)s.size(); i++) {
    if (s.substr(i, p.size()) == p) {
      res++;
    }
  }
  return res;
}

word merge(const word &a, const word &b) {
  word c;
  c.len = a.len + b.len;
  c.s = a.s + b.s;
  c.cnt = a.cnt + b.cnt + cnt(getlst(a.s) + getfst(b.s), "haha");
  if ((int)c.s.size() >= 7) {
    c.s = getfst(c.s) + '@' + getlst(c.s);
  }
  return c;
}

void solve() {
  int n;
  std::cin >> n;
  std::map<std::string, word> vars;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    std::string var, op;
    std::cin >> var >> op;
    if (op == "=") {
      std::string a, plus, b;
      std::cin >> a >> plus >> b;
      vars[var] = merge(vars[a], vars[b]);
    } else {
      std::string s;
      std::cin >> s;
      word w;
      w.len = s.length();
      w.cnt = cnt(s, "haha");
      w.s = s;
      vars[var] = w;
    }
    ans = vars[var].cnt;
  }

  std::cout << ans << '\n';
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
