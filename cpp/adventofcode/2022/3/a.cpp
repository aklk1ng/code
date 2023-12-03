#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve1() {
  ifstream f("input.txt");
  string line;
  ll res = 0;
  while (getline(f, line)) {
    int n = line.size();
    string lhs, rhs;
    string s = "";
    set<char> v1;
    set<char> v2;
    for (int i = 0; i < n / 2; i++) {
      v1.insert(line[i]);
    }
    for (int i = n / 2; i < n; i++) {
      v2.insert(line[i]);
    }
    for (auto &c : v2) {
      if (v1.count(c)) {
        s += c;
      }
    }
    for (auto &c : s) {
      if (isupper(c)) {
        res += 27 + int(c - 'A');
      } else {
        res += 1 + int(c - 'a');
      }
    }
  }
  cout << res << '\n';
}

void solve2() {
  ifstream f("input.txt");
  string line;
  ll res = 0;
  int cnt = 0;
  vector<string> v;

  auto parse = [&](string str) {
    set<char> s;
    string ret;
    for (char &c : str) {
      if (!s.count(c)) {
        ret += c;
        s.insert(c);
      }
    }
    return ret;
  };
  while (getline(f, line)) {
    cnt++;
    v.push_back(line);
    if (cnt < 3) {
      continue;
    }
    vector<int> hash(53);
    for (auto &s : v) {
      s = parse(s);
      for (auto &c : s) {
        if (isupper(c)) {
          hash[c - 'A' + 27]++;
        } else {
          hash[c - 'a' + 1]++;
        }
      }
    }
    for (int i = 0; i < 53; i++) {
      if (hash[i] == 3) {
        res += i;
      }
    }
    cnt = 0;
    v.clear();
  }
  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // solve1();
  solve2();

  return 0;
}
