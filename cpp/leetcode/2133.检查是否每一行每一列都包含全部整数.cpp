#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  bool checkValid(vector<vector<int>> &matrix) {
    unordered_set<int> cnt;
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      cnt.clear();
      for (int j = 0; j < n; j++) {
        if (cnt.count(matrix[i][j]))
          return false;
        cnt.insert(matrix[i][j]);
      }
    }

    for (int j = 0; j < n; j++) {
      cnt.clear();
      for (int i = 0; i < n; i++) {
        if (cnt.count(matrix[i][j]))
          return false;
        cnt.insert(matrix[i][j]);
      }
    }
    return true;
  }
};
