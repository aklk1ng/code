#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    map<int, int> ps;
    for (int i = 0; i < position.size(); i++)
      ps[position[i]] = speed[i];

    int ans = 0;
    stack<float> st;
    for (auto &[pos, spd] : ps) {
      float time = float(target - pos) / spd;
      while (!st.empty() && time >= st.top())
        st.pop();

      st.push(time);
    }
    return st.size();
  }
};
