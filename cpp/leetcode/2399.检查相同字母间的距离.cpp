#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  bool checkDistances(string s, vector<int> distance) {
    vector<int> Index(26);
    for (int i = 0; i < s.size(); i++) {
      int idx = s[i] - 'a';
      if (Index[idx] && i - Index[idx] != distance[idx])
        return false;
    }
    return true;
  }
};
