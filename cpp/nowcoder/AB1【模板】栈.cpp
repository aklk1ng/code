#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v;
  string op;
  for (int i = 0; i < n; i++) {
    cin >> op;
    if (op == "push") {
      int q;
      cin >> q;
      v.push_back(q);
    } else if (op == "pop") {
      if (v.empty()) {
        cout << "error" << endl;
        continue;
      }
      cout << *(v.end() - 1) << endl;
      v.erase(v.end() - 1);
    } else if (op == "top") {
      if (v.empty()) {
        cout << "error" << endl;
        continue;
      }
      cout << *(v.end() - 1) << endl;
    }
  }
};
