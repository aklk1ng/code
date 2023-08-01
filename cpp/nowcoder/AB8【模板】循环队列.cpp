#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> v;
  string op;
  for (int i = 0; i < q; i++) {
    cin >> op;
    if (op == "push") {
      int num;
      cin >> num;
      if (v.size() == n)
        cout << "full" << endl;
      else
        v.push_back(num);
    } else if (op == "front") {
      if (v.empty())
        cout << "error" << endl;
      else
        cout << v[0] << endl;
    } else if (op == "pop") {
      if (v.empty())
        cout << "error" << endl;
      else {
        cout << v[0] << endl;
        v.erase(v.begin());
      }
    }
  }
  return 0;
};
