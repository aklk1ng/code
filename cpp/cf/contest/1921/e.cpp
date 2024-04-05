#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int h, w, xA, yA, xB, yB;
  std::cin >> h >> w >> xA >> yA >> xB >> yB;

  bool win;
  std::string winner;
  int turns = 0;
  if ((xA - xB) % 2 == 0) {
    winner = "Bob";
    if (xA >= xB) {
      win = false;
    } else if (yA == yB) {
      win = true;
    } else {
      if (yA < yB) {
        turns = yB - 1;
      } else {
        turns = w - yB;
      }
      win = xB - 2 * turns >= xA;
    }
  } else {
    winner = "Alice";
    xA += 1;
    if (yB - yA > 0) {
      yA += 1;
    } else if (yB - yA < 0) {
      yA -= 1;
    }

    if (xA > xB) {
      win = false;
    } else if (yA == yB) {
      win = true;
    } else {
      if (yA < yB) {
        turns = w - yA;
      } else {
        turns = yA - 1;
      }
      win = xB - 2 * turns >= xA;
    }
  }

  std::cout << (win ? winner : "Draw") << '\n';
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
