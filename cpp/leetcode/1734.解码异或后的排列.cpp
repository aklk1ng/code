#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> decode(vector<int> &encoded) {
    int n = encoded.size() + 1;
    int total = 0;
    for (int i = 1; i <= n; i++)
      total ^= i;
    int old = 0;
    for (int i = 1; i < n; i += 2)
      old ^= encoded[i];

    vector<int> perm(n);
    perm[0] = total ^ old;
    for (int i = 1; i < n - 1; i++)
      perm[i + 1] = perm[i] ^ encoded[i];
    return perm;
  }
};
