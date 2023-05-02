#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++) {
      if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
        int num1 = st.top();
        st.pop();
        int num2 = st.top();
        st.pop();
        if (tokens[i] == "+")
          st.push(num2 + num1);
        else if (tokens[i] == "-")
          st.push(num2 - num1);
        else if (tokens[i] == "*")
          st.push(num2 * num1);
        else if (tokens[i] == "/")
          st.push(num2 / num1);
      } else
        st.push(stoi(tokens[i]));
    }
    int res = st.top();
    st.pop();
    return res;
  }
};

int main(int argc, char *argv[]) {
  cout << "hello world" << endl;
  return 0;
}
