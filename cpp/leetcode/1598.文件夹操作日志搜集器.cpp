#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int minOperations(vector<string> &logs) {
    int depth = 0;
    for (auto &log : logs) {
      if (log == "./")
        continue;
      else if (log == "../") {
        if (depth > 0)
          depth--;
      } else
        depth++;
    }
    return depth;
  }
};
