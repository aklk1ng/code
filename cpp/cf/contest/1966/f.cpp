#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::vector<int> getsubarray(std::vector<int> a) {
  std::vector<int> res;
  for (int i = 0; i < a.size(); i++) {
    int sum = 0;
    for (int j = i; j < a.size(); j++) {
      sum += a[j];
      res.push_back(sum);
    }
  }
  std::sort(res.begin(), res.end());
  return res;
}

std::vector<int> getodd(std::vector<int> a) {
  std::vector<int> res;
  for (auto &e : a) {
    if (res.size() && e == res.back()) {
      res.pop_back();
    } else {
      res.push_back(e);
    }
  }
  return res;
}

std::vector<int> getpalindrome(std::vector<int> odds, int n) {
  std::vector<int> res(n);
  int pre = 0, idx = (n - 1) / 2;
  for (auto &e : odds) {
    if (idx == n - 1 - idx) {
      res[idx] = e;
    } else {
      res[idx] = (e - pre) / 2;
      res[n - 1 - idx] = (e - pre) / 2;
    }
    pre = e;
    idx--;
  }
  return res;
}

int getlargest(std::vector<int> lhs, std::vector<int> rhs) {
  while (!rhs.empty() && lhs.back() == rhs.back()) {
    lhs.pop_back();
    rhs.pop_back();
  }
  return lhs.back();
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> s((n * (n + 1)) / 2 - 1);
  for (int i = 0; i < (n * (n + 1)) / 2 - 1; i++) {
    std::cin >> s[i];
  }

  std::sort(s.begin(), s.end());
  auto odds = getodd(s);

  int miss = -1;
  if (odds.size() > (n + 1) / 2) {
    std::vector<int> odd, even;
    for (auto &e : odds) {
      if (e % 2) {
        odd.push_back(e);
      } else {
        even.push_back(e);
      }
    }

    if (!odd.empty() && !even.empty()) {
      miss = even.size() == 1 ? even[0] : odd[0];
    } else {
      auto b = getpalindrome(odds, n + 2);
      auto bsum = getsubarray(b);
      int y = bsum.back();
      int x = getlargest(bsum, s);
      miss = 2 * x - y;
    }
  } else {
    auto b = getpalindrome(odds, n - 2);
    auto bsum = getsubarray(b);
    int y = bsum.back();
    int x = getlargest(s, bsum);
    miss = 2 * x - y;
  }
  odds.push_back(miss);
  std::sort(odds.begin(), odds.end());
  odds = getodd(odds);

  auto ans = getpalindrome(odds, n);
  for (auto &e : ans) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
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
