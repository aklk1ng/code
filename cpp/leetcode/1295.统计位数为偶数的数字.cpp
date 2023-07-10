#include <bits/stdc++.h>

using namespace std;

class Soluton1 {
public:
  int g(int num) {
    int cnt = 0;
    while (num) {
      num /= 10;
      cnt++;
    }
    return cnt;
  }
  int findNumbers(vector<int> &nums) {
    int res = 0;
    for (auto num : nums)
      if (g(num) % 2 == 0)
        res++;
    return res;
  }
};

class Soluton2 {
public:
  int findNumbers(vector<int> &nums) {
    int res = 0;
    for (auto num : nums)
      if (to_string(num).size() % 2 == 0)
        res++;
    return res;
  }
};

class Soluton3 {
public:
  int findNumbers(vector<int> &nums) {
    int res = 0;
    for (auto num : nums)
      if (((int)log10(num) + 1) % 2 == 0)
        res++;
    return res;
  }
};
