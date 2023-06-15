#include <bits/stdc++.h>

using namespace std;

class Soluton1 {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> st;
    vector<int> res(temperatures.size(), 0);
    st.push(0);
    for (int i = 1; i < temperatures.size(); i++) {
      if (temperatures[i] <= temperatures[st.top()])
        st.push(i);
      else {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
          res[st.top()] = i - st.top();
          st.pop();
        }
        st.push(i);
      }
    }
    return res;
  }
};

class Soluton2 {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> st;
    vector<int> res(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        res[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }
    return res;
  }
};
