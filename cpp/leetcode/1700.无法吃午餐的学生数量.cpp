#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countStudent(vector<int> &students, vector<int> &sandwitches) {
    int s1 = accumulate(students.begin(), students.end(), 0);
    int s0 = students.size() - s1;
    for (auto &tmp : sandwitches) {
      if (tmp == 0 && s0 > 0)
        s0--;
      else if (tmp == 1 && s1 > 0)
        s1--;
      else
        break;
    }
    return s0 + s1;
  }
};
