#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        (i == j || i == n - 1 - j) ? cout << "*" : cout << " ";
      cout << endl;
    }
  }
  return 0;
}
