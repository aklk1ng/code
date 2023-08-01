#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string op;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (op == "push") {
      int q;
      cin >> q;
      v.push_back(q);
    } else if (op == "pop") {
      if (v.empty())
        cout << "error" << endl;
      else {
        cout << v[0] << endl;
        v.erase(v.begin());
      }
    } else if (op == "front") {
      if (v.empty())
        cout << "error" << endl;
      else
        cout << v[0] << endl;
    }
  }
  return 0;
};
