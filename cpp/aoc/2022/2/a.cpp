#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve1() {
  ifstream f("input.txt");
  string line;
  ll res = 0;

  auto win = [&](string lhs, string rhs) {
    if ((lhs == "A" && rhs == "Y") || (lhs == "B" && rhs == "Z") || (lhs == "C" && rhs == "X")) {
      return true;
    }
    return false;
  };
  auto draw = [&](string lhs, string rhs) {
    if ((lhs == "A" && rhs == "X") || (lhs == "B" && rhs == "Y") || (lhs == "C" && rhs == "Z")) {
      return true;
    }
    return false;
  };
  auto score = [&](string c) {
    if (c == "X") {
      return 1;
    } else if (c == "Y") {
      return 2;
    } else {
      return 3;
    }
  };

  while (getline(f, line)) {
    istringstream input(line);
    string lhs, rhs;
    input >> lhs >> rhs;
    res += score(rhs);
    if (win(lhs, rhs)) {
      res += 6;
    } else if (draw(lhs, rhs)) {
      res += 3;
    }
  }
  cout << res << '\n';
}

void solve2() {
  ifstream f("input.txt");
  string line;
  ll res = 0;
  auto score = [&](char lhs, char rhs) {
    if (rhs == 'X') {
      if (lhs == 'A') {
        res += 3;
      } else if (lhs == 'B') {
        res += 1;
      } else {
        res += 2;
      }
    } else if (rhs == 'Y') {
      res += 3;
      res += lhs - 'A' + 1;
    } else {
      res += 6;
      if (lhs == 'A') {
        res += 2;
      } else if (lhs == 'B') {
        res += 3;
      } else {
        res += 1;
      }
    }
  };
  while (getline(f, line)) {
    istringstream input(line);
    char lhs, rhs;
    input >> lhs >> rhs;
    score(lhs, rhs);
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
