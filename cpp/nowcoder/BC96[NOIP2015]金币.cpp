#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 1; n > 0; i++) {
    if (n >= i)
      res += i * i;
    else
      res += i * n;
    n -= i;
  }
  cout << res << endl;
  return 0;
}
