#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<string> st;
    auto operation = [&](string op) -> int {
      int rhs = stoi(st.top());
      st.pop();
      int lhs = stoi(st.top());
      st.pop();
      if (op == "+")
        return lhs + rhs;
      else if (op == "-")
        return lhs - rhs;
      else if (op == "*")
        return lhs * rhs;
      else
        return lhs / rhs;
    };
    for (auto &token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        st.push(to_string(operation(token)));
      } else
        st.push(token);
    }
    return stoi(st.top());
  }
};
