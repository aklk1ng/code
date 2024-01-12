#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  map<int, map<char, vector<string>>> m;
  auto check = [&](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };
  auto Count = [&](const string &w) {
    int res = 0;
    for (auto &e : w) {
      if (check(e)) {
        res++;
      }
    }
    return res;
  };
  auto lastVowel = [&](const string &w) {
    for (int i = (int)w.size() - 1; i >= 0; i--) {
      if (check(w[i])) {
        return w[i];
      }
    }
    throw "No vowels";
  };
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    int cnt = Count(s[i]);
    char lst = lastVowel(s[i]);
    m[cnt][lst].push_back(s[i]);
  }

  vector<pair<string, string>> t1, t2;
  for (auto &e : m) {
    for (auto &v : e.second) {
      while (v.second.size() >= 2) {
        string fst = v.second.back();
        v.second.pop_back();
        string sec = v.second.back();
        v.second.pop_back();
        t1.push_back({fst, sec});
      }
    }

    vector<string> remains;
    for (auto &v : e.second) {
      for (auto &w : v.second) {
        remains.push_back(w);
      }
    }
    while (remains.size() >= 2) {
      string fst = remains.back();
      remains.pop_back();
      string sec = remains.back();
      remains.pop_back();
      t2.push_back({fst, sec});
    }
  }

  vector<pair<string, string>> lyric;
  while (!t2.empty() && !t1.empty()) {
    auto fst = t2.back();
    t2.pop_back();
    auto sec = t1.back();
    t1.pop_back();
    lyric.push_back({fst.first, sec.first});
    lyric.push_back({fst.second, sec.second});
  }
  while (t1.size() >= 2) {
    auto fst = t1.back();
    t1.pop_back();
    auto sec = t1.back();
    t1.pop_back();
    lyric.push_back({fst.first, sec.first});
    lyric.push_back({fst.second, sec.second});
  }

  cout << lyric.size() / 2 << '\n';
  for (auto &e : lyric) {
    cout << e.first << ' ' << e.second << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
