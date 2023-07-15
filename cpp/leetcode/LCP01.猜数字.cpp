#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int game(vector<int> &guess, vector<int> &answer) {
    int ans = 0;
    for (int i = 0; i < 3; i++)
      ans += (guess[i] == answer[i]);
    return ans;
  }
};
