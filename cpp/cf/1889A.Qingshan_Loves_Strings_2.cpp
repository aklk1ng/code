#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  if (std::count(s.begin(), s.end(), '0') !=
      std::count(s.begin(), s.end(), '1')) {
    std::cout << "-1\n";
    return;
  }

  std::vector<int> z;
  std::deque<char> q;
  for (int i = 0; i < n; i++) {
    q.push_back(s[i]);
  }

  int d = 0;
  while (!q.empty()) {
    if (q.front() == q.back()) {
      if (q.front() == '0') {
        q.push_back('0');
        q.push_back('1');
        z.push_back(n - d);
      } else {
        q.push_front('1');
        q.push_front('0');
        z.push_back(d);
      }
      n += 2;
    }
    while (!q.empty() && q.front() != q.back()) {
      q.pop_back();
      q.pop_front();
      d++;
    }
  }

  std::cout << z.size() << '\n';
  for (int i = 0; i < (int)z.size(); i++) {
    std::cout << z[i] << " \n"[i == (int)z.size() - 1];
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
