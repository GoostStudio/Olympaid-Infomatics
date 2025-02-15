#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<char>> grid;
vector<vector<int>> dp;

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M && grid[x][y] == 'P';
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> M;
    grid.resize(N, vector<char>(M));
    dp.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    int maxTroops = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'P') {
                bool canPlace = true;
                for (int dx = -2; dx <= 2; ++dx) {
                    for (int dy = -2; dy <= 2; ++dy) {
                        if (abs(dx) + abs(dy) <= 2 && isValid(i + dx, j + dy) && dp[i + dx][j + dy] > 0) {
                            canPlace = false;
                            break;
                        }
                    }
                    if (!canPlace) break;
                }
                if (canPlace) {
                    dp[i][j] = 1;
                    maxTroops++;
                }
            }
        }
    }

    cout << maxTroops << endl;

    return 0;
}