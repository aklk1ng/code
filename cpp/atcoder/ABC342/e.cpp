#include <bits/stdc++.h>
typedef long long ll;

struct train {
  int from, to;
  ll fst;
  ll val;
  ll cnt;
  ll dist;

  std::optional<ll> get_lst(ll time) const {
    if (time < fst + dist) {
      return std::nullopt;
    }
    return fst + std::min(cnt - 1, (time - fst - dist) / val) * val;
  };
};

void solve() {
  int N, M;
  std::cin >> N >> M;

  std::vector info(N, std::vector<train>());
  while (M--) {
    ll l, d, k, c;
    int A, B;
    std::cin >> l >> d >> k >> c >> A >> B;
    info[--B].push_back({--A, --B, l, d, k, c});
  }

  std::priority_queue<std::pair<ll, int>> pq;
  std::vector<ll> ans(N);
  pq.emplace(ans.back() = std::numeric_limits<ll>::max(), N - 1);
  while (!pq.empty()) {
    auto [time, now] = pq.top();
    pq.pop();
    if (ans[now] > time) {
      continue;
    }

    for (auto &e : info[now]) {
      auto nxt{e.from};
      auto nxt_time{e.get_lst(time)};

      if (nxt_time && ans[nxt] < *nxt_time) {
        pq.emplace(ans[nxt] = *nxt_time, nxt);
      }
    }
  }

  for (auto &d : ans | std::views::take(N - 1)) {
    if (d) {
      std::cout << d << '\n';
    } else {
      std::cout << "Unreachable\n";
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
