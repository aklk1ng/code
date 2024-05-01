#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

ll n;
std::vector<std::pair<ll, ll>> vec;
std::map<ll, std::pair<ll, ll>> blocks;

std::pair<ll, ll> cal() {
  std::set<std::pair<ll, ll>> widest, longest;

  for (size_t i = 0; i < vec.size(); i++) {
    widest.insert({vec[i].first, i});
    longest.insert({vec[i].second, i});

    blocks[i] = vec[i];
  }

  std::pair<ll, ll> ans = {-1, -1};
  bool mode = 0;
  ll prevw = INT_MAX, prevh = INT_MAX, prv = -1;
  bool cringe = 0;
  while (widest.size() != 0) {
    if (mode == 0) {
      ll cur = (*widest.rbegin()).first, sum = 0;
      if (ans.second == -1)
        ans.second = cur;
      prv = blocks[(*widest.rbegin()).second].second;

      while (widest.size() > 0 && (*widest.rbegin()).first == cur) {
        auto it = (--widest.end());
        longest.erase({blocks[it->second].second, it->second});
        sum += blocks[it->second].second;
        widest.erase(it);
      }

      if (!cringe) {
        ans.first = sum;
      }
      prv = sum;
      if (prevw == INT_MAX) {
        prevh = cur;
      } else {
        prevw -= sum;
        if (prevh != cur) {
          return {-1, -1};
        }
      }
    } else {
      ll cur = (*longest.rbegin()).first, sum = 0;
      if (!cringe) {
        ans.first = cur + prv;
        cringe = 1;
      }

      while (longest.size() > 0 && (*longest.rbegin()).first == cur) {
        auto it = (--longest.end());
        widest.erase({blocks[it->second].first, it->second});
        sum += blocks[it->second].first;
        longest.erase(it);
      }

      if (prevw == INT_MAX) {
        prevw = cur;
        prevh -= sum;
        if (prevw != cur) {
          return {-1, -1};
        }
      } else {
        prevh -= sum;
        if (prevw != cur) {
          return {-1, -1};
        }
      }
    }

    mode ^= 1;
  }

  if (prevh == 0 || prevw == 0 || prevh == INT_MAX || prevw == INT_MAX) {
    return ans;
  } else {
    return {-1, -1};
  }
}

void solve() {
  std::cin >> n;

  vec.clear();
  blocks.clear();
  vec.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i].first >> vec[i].second;
  }
  std::vector<std::pair<ll, ll>> ans;
  ans.push_back(cal());
  std::swap(ans.back().first, ans.back().second);
  if (ans.back().first == -1) {
    ans.pop_back();
  }
  for (auto &e : vec) {
    std::swap(e.first, e.second);
  }
  ans.push_back(cal());
  if (ans.back().first == -1) {
    ans.pop_back();
  }
  if (ans.size() == 2 && ans[0] == ans[1]) {
    ans.pop_back();
  }
  std::cout << ans.size() << '\n';
  for (auto &e : ans) {
    std::cout << e.first << ' ' << e.second << '\n';
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
