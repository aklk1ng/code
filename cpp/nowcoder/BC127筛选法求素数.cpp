#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  int cnt = 0;
  while (cin >> n) {
    for (int i = 2; i <= n; i++) {
      bool flag = true;
      for (int j = 2; j < i; j++)
        if (i % j == 0) {
          flag = false;
          break;
        }
      if (flag) {
        cout << i << " ";
        cnt++;
      }
    }
    cout << endl;
    cout << n - cnt - 1 << endl;
  }
  return 0;
}
