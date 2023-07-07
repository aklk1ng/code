#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  vector<int> decode(vector<int> &decoded, int first) {
    int n = decoded.size() + 1;
    vector<int> arr(n);
    for (int i = 1; i < n; i++)
      arr[i] = arr[i - 1] ^ decoded[i - 1];
    return arr;
  }
};
