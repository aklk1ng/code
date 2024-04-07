#include <bits/stdc++.h>
typedef long long ll;

struct Stu {
  int k, s, tin = 0;

  bool operator<(const Stu &ohs) const {
    if (k == ohs.k) {
      if (tin == ohs.tin) {
        return s > ohs.s;
      }
      return tin > ohs.tin;
    }
    return k < ohs.k;
  }
};

void solve() {
  int n, D;
  std::cin >> n >> D;
  int x = 1;
  std::vector<Stu> q(n);
  for (int i = 0; i < n; i++) {
    std::cin >> q[i].k >> q[i].s;
  }

  std::vector<int> suf(n);
  suf[n - 1] = q[n - 1].k;
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = std::max(q[i].k, suf[i + 1]);
  }

  std::vector eat(D, std::vector<Stu>());
  auto check = [&]() {
    int pos = 0;
    std::priority_queue<Stu> pq;
    for (int i = 0; i < D && pos < n; i++) {
      if (pq.empty() || pq.top().k <= suf[pos]) {
        ll nxt = i + (ll)x * q[pos].s;
        if (nxt < D) {
          eat[nxt].push_back(q[pos]);
        }
        pos++;
        if (pos == n) {
          return i + 1;
        }
      } else {
        ll nxt = i + (ll)x * pq.top().s;
        if (nxt < D) {
          eat[nxt].push_back(pq.top());
        }
        pq.pop();
      }

      for (auto &e : eat[i]) {
        pq.push({e.k, e.s, i});
      }
    }
    return -1;
  };

  std::cout << check() << '\n';
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
