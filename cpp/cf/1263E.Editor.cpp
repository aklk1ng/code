#include <bits/stdc++.h>
typedef long long ll;

struct ms {
  int cnt = 0;
  int allopens = 0;
  std::stack<int> s, mi, mx;

  void push(int x) {
    s.push(x);
    cnt += x;
    if (x == 1) {
      allopens++;
    }
    mi.push(mi.size() ? std::min(mi.top(), cnt) : cnt);
    mx.push(mx.size() ? std::max(mx.top(), cnt) : cnt);
  }

  void pop() {
    if (s.empty()) {
      return;
    }
    cnt -= s.top();
    if (s.top() == 1) {
      allopens--;
    }
    s.pop();
    mi.pop();
    mx.pop();
  }

  int top() { return s.top(); }

  bool isCorrect() { return (mx.empty() || mi.top() >= 0); }

  int depth() { return (!mx.empty() ? mx.top() : 0); }
};

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  ms l, r;
  std::vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    r.push(0);
  }
  l.push(0);
  int pos = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      if (pos) {
        pos--;
        r.push(-l.top());
        l.pop();
      }
    } else if (s[i] == 'R') {
      pos++;
      l.push(-r.top());
      r.pop();
    } else if (s[i] == '(') {
      l.pop();
      l.push(1);
    } else if (s[i] == ')') {
      l.pop();
      l.push(-1);
    } else {
      l.pop();
      l.push(0);
    }
    if (l.isCorrect() && r.isCorrect() && l.cnt == r.cnt) {
      std::cout << std::max({l.depth(), r.depth(), l.cnt}) << ' ';
    } else {
      std::cout << "-1 ";
    }
  }
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
