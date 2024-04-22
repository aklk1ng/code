#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

std::vector<int> ans(N), primes;
std::bitset<N> isprime;

std::vector<int> cal(int l) {
  isprime.set();
  isprime[0] = isprime[1] = false;
  for (int i = 4; i < l; i += 2) {
    isprime[i] = false;
  }
  for (int i = 3; i * i < l; i += 2) {
    if (isprime[i]) {
      for (int j = i * i; j < l; j += i * 2) {
        isprime[j] = false;
      }
    }
  }
  std::vector<int> res;
  for (int i = 2; i < l; i++) {
    if (isprime[i]) {
      res.push_back(i);
    }
  }
  return res;
}

void init() {
  primes = cal(N);
  std::vector<int> del(N);
  for (auto &e : primes) {
    for (int i = e; i < N; i += e) {
      int inc = (e - ((i / e) % e)) % e;
      del[i] = (del[i] + inc) % mod;
      if (i + e < N) {
        del[i + e] = (del[i + e] - inc + mod) % mod;
      }
    }
  }
  for (int i = 4; i < N; i += 4) {
    int inc = (2 * (i / 4)) % 4;
    del[i] = (del[i] + inc) % mod;
    if (i + 4 < N) {
      del[i + 4] = (del[i + 4] - inc + mod) % mod;
    }
  }
  int pref = 0;
  for (int i = 1; i < N; i++) {
    pref = (pref + del[i]) % mod;
    ans[i] = (ans[i - 1] + pref) % mod;
  }
}

void solve() {
  int n;
  std::cin >> n;
  std::cout << ans[n] << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  init();
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
