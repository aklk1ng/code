#include <bits/stdc++.h>

using namespace std;

int main() {
  double a, b, c;
  while (cin >> a >> b >> c) {
    if (a == 0)
      cout << "Not quadratic equation\n";
    else {
      double bin = pow(b, 2) - 4 * a * c;
      if (bin > 0) {
        double x1 = (-b - sqrt(bin)) / 2 / a;
        double x2 = (-b + sqrt(bin)) / 2 / a;
        cout << setiosflags(ios::fixed) << setprecision(2);
        cout << "x1=" << x1 << ';' << "x2=" << x2 << endl;
      } else if (bin == 0) {
        double x2 = (-b + sqrt(bin)) / 2 / a;
        if (x2 == 0)
          cout << "x1=x2=0.00" << endl;
        else {
          cout << setiosflags(ios::fixed) << setprecision(2);
          cout << "x1=x2=" << x2 << endl;
        }
      } else {
        double xu = sqrt(bin * (-1)) / 2 / a;
        double shi = -1 * b / 2 / a;
        cout << setiosflags(ios::fixed) << setprecision(2);
        cout << "x1=" << shi << '-' << xu << 'i' << ';' << "x2=" << shi << '+' << xu << 'i' << endl;
      }
    }
  }
}
