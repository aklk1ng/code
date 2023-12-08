#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve1() {
  ifstream f("input.txt");
  string line;
  int res = 0;
  while (getline(f, line)) {
    string a, b, c, d;
    string s;
    size_t pos = line.find(',');
    s = line.substr(0, pos);
    size_t t = s.find('-');
    a = s.substr(0, t);
    b = s.substr(t + 1);
    s = line.substr(pos + 1);
    t = s.find('-');
    c = s.substr(0, t);
    d = s.substr(t + 1);
    a = stoi(a);
    b = stoi(b);
    c = stoi(c);
    d = stoi(d);
    if ((a <= c && b >= d) || (c <= a && d >= b)) {
      res++;
    }
  }
  cout << res << '\n';
}

void solve2() {
  ifstream f("input.txt");
  string line;
  int res = 0;
  while (getline(f, line)) {
    string a, b, c, d;
    string s;
    size_t pos = line.find(',');
    s = line.substr(0, pos);
    size_t t = s.find('-');
    a = s.substr(0, t);
    b = s.substr(t + 1);
    s = line.substr(pos + 1);
    t = s.find('-');
    c = s.substr(0, t);
    d = s.substr(t + 1);
    a = stoi(a);
    b = stoi(b);
    c = stoi(c);
    d = stoi(d);
    if (b < c || d < a) {
      continue;
    }
    res++;
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
