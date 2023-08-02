#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  int res = 0, tmp, cnt = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    tmp = (s[i] - '0') % 2;
    res += tmp * pow(10, cnt++);
  }
  cout << res;
  return 0;
}
