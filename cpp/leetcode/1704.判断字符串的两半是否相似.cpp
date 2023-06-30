#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  bool halvesAreALike(string s) {
    string a = s.substr(0, s.size() / 2);
    string b = s.substr(s.size() / 2);
    string h = "aeiouAEIOU";
    int cnta = 0, cntb = 0;

    for (char c : a)
      if (h.find_first_of(c) != string::npos)
        cnta++;
    for (char c : a)
      if (h.find_first_of(c) != string::npos)
        cntb++;

    return cnta == cntb;
  }
};
