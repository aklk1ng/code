#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int N;
  std::cin >> N;

  auto add{[](int x) { return [x](auto &&pq) { pq.first.push(x); }; }};
  auto erase{[](int x) { return [x](auto &&pq) { pq.second.push(x); }; }};
  auto check{[](auto &&pq) {
    while (!std::empty(pq.second) && pq.first.top() == pq.second.top()) {
      pq.first.pop();
      pq.second.pop();
    }
    return std::empty(pq.first) ? 0 : pq.first.top();
  }};
  std::vector<std::pair<std::priority_queue<int>, std::priority_queue<int>>>
      vals(2 * N);
  for (int i = 0; i < N; i++) {
    int a;
    std::cin >> a;
    add(a)(vals[i + N]);
  }

  auto update{[N, &vals](ll l, ll r, const auto callback) {
    l += N;
    r += N;
    while (l != r) {
      if (l & 1) {
        callback(vals[l++]);
      }
      if (r & 1) {
        callback(vals[--r]);
      }
      l /= 2;
      r /= 2;
    }
  }};
  auto access{[N, &vals](int i, const auto &m, const auto &g) {
    i += N;
    int ret{};
    while (i) {
      ret = g(ret, m(vals[i]));
      i /= 2;
    }
    return ret;
  }};

  int Q;
  std::cin >> Q;
  std::vector<std::tuple<int, int, int>> ins(Q);
  for (auto &&[l, r, x] : ins) {
    int op;
    std::cin >> op;
    if (op == 1) {
      std::cin >> l >> r >> x;
      l--;
      update(l, r, add(x));
    } else if (op == 2) {
      std::cin >> x;
      auto &[l_erased, r_erased, x_erased]{ins[x - 1]};
      update(l_erased, r_erased, erase(x_erased));
    } else {
      std::cin >> x;
      std::cout << access(x - 1, check, [](auto a, auto b) {
        return std::max(a, b);
      }) << '\n';
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
