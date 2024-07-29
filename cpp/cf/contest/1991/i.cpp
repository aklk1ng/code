#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 15, dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int n, m, x, y, grid[N][N], color[N][N], visited[N][N], currentValue,
    currentColor, flipCoords;

bool isAdjacent(int x, int y) {
    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (1 <= nx && nx <= n && 1 <= ny && ny <= m && visited[nx][ny]) {
            return true;
        }
    }
    return false;
}

void interact() {
    std::cin >> x >> y;
    if (flipCoords) {
        std::swap(x, y);
    }
    visited[x][y] = 1;
}

void output(int x, int y) {
    visited[x][y] = 1;
    if (flipCoords) {
        std::cout << y << ' ' << x << std::endl;
    } else {
        std::cout << x << ' ' << y << std::endl;
    }
}

void placePair(int x1, int y1, int x2, int y2) {
    grid[x1][y1] = ++currentValue;
    grid[x2][y2] = ++currentValue;
    color[x1][y1] = color[x2][y2] = ++currentColor;
}

void placeTShape(int x, int y) {
    int largestValue = n * m - 12 + currentColor * 3;
    grid[x][y] = ++currentValue;
    color[x][y] = ++currentColor;
    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
            grid[nx][ny] = ++largestValue;
            color[nx][ny] = currentColor;
        }
    }
}

void printGrid() {
    if (!flipCoords)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                std::cout << grid[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    else
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                std::cout << grid[j][i] << ' ';
            }
            std::cout << std::endl;
        }
}

void fillHorizontalPairs() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            if (!grid[i][j] && !grid[i][j + 1]) {
                placePair(i, j, i, j + 1);
            }
        }
    }
}

void fillVerticalPairs() {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!grid[i][j] && !grid[i + 1][j]) {
                placePair(i, j, i + 1, j);
            }
        }
    }
}

void solve() {
    std::cin >> n >> m;
    memset(grid, 0, sizeof(grid));
    memset(color, 0, sizeof(color));
    memset(visited, 0, sizeof(visited));
    currentColor = currentValue = flipCoords = 0;
    if (n % 2 == 1 && m % 2 == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < m; j += 2) {
                placePair(i, j, i, j + 1);
            }
        }
        for (int i = 1; i <= n; i += 2) {
            placePair(i, m, i + 1, m);
        }
        grid[n][m] = n * m;
        printGrid();
        for (int i = 1; i < n * m; i += 2) {
            interact();
            bool selected = false;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (!visited[i][j] && color[i][j] == color[x][y]) {
                        output(i, j);
                        selected = true;
                        break;
                    }
                }
                if (selected) {
                    break;
                }
            }
            if (selected) {
                continue;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (!visited[i][j] && isAdjacent(i, j) &&
                        grid[i][j] != n * m) {
                        output(i, j);
                        i = n;
                        j = m;
                    }
                }
            }
        }
        std::cin >> x >> y;
        return;
    }
    if (n > m) {
        std::swap(n, m);
        flipCoords = 1;
    }
    if (n == 4 && m == 4) {
        placeTShape(1, 2);
        placeTShape(2, 4);
        placeTShape(3, 1);
        placeTShape(4, 3);
    } else if (n == 4 && m == 5) {
        placeTShape(1, 2);
        placeTShape(3, 1);
        placeTShape(3, 5);
        placeTShape(4, 3);
        fillHorizontalPairs();
    } else {
        placeTShape(1, 2);
        placeTShape(3, 1);
        placeTShape(1, m - 1);
        placeTShape(3, m);
        placePair(2, 3, 3, 3);
        placePair(4, 2, 4, 3);
        placePair(2, m - 2, 3, m - 2);
        placePair(4, m - 2, 4, m - 1);
        if (m % 2 == 0) {
            fillHorizontalPairs();
        } else {
            fillVerticalPairs();
        }
    }
    printGrid();
    for (int i = 1; i <= n * m; i += 2) {
        interact();
        std::pair bestMove = {-1, -1};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!visited[i][j] && color[i][j] == color[x][y] &&
                    (bestMove.first == -1 ||
                     grid[i][j] < grid[bestMove.first][bestMove.second])) {
                    bestMove = {i, j};
                }
            }
        }
        output(bestMove.first, bestMove.second);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    if (true) {
        std::cin >> _;
    }
    while (_--) {
        solve();
    }

    return 0;
}
