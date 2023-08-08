#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  int cnt = 1;
  int row = 0, col = 0;
  vector<vector<int>> grid(n, vector<int>(n, 0));
  while (cnt <= n * n) {
    for (int i = 0; i < 2; i++) {
      grid[row][col] = cnt++;
      col++;
    }
    col--;
    while (col) {
      row++;
      col--;
      if (row < n && col < n)
        grid[row][col] = cnt++;
    }
    row++;
    while (row) {
      if (row < n && col < n)
        grid[row][col] = cnt++;
      row--;
      col++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << grid[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
