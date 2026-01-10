/* 994. Rotting Oranges */
/** You are given an m x n grid where each cell can have one of three values:
 * 
 *  0 representing an empty cell,
 *  1 representing a fresh orange, or
 *  2 representing a rotten orange.
 *  Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
 *  Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
 * 
 *  Example 1:
 *  Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 *  Output: 4
 * 
 *  Example 2:
 *  Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 *  Output: -1
 *  Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
 * 
 *  Example 3:
 *  Input: grid = [[0,2]]
 *  Output: 0
 *  Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 * 
 *  Constraints:
 *  m == grid.length
 *  n == grid[i].length
 *  1 <= m, n <= 10
 *  grid[i][j] is 0, 1, or 2. **/

#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

// up, right, down, left
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool seen[11][11];

int bfs(queue<pair<int,int>> &queue, int orangeCount, vector<vector<int>> &grid) {
    int minute = -1;
    int rottenCount = 0;

    while (!queue.empty()) {
        int size = queue.size();
        minute++;
        rottenCount += size;

        for (int i = 0; i < size; ++i) {
            int row = queue.front().first;
            int col = queue.front().second;
            queue.pop();

            for (int j = 0; j < 4; ++j) {
                int nextRow = row + dr[j];
                int nextCol = col + dc[j];

                if (nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size()) continue;
                if (seen[nextRow][nextCol] || grid[nextRow][nextCol] == 0) continue;
                
                seen[nextRow][nextCol] = true;
                queue.push(make_pair(nextRow, nextCol));
            }
        }
    }

    return orangeCount == rottenCount ? minute : -1;
}

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>> queue;
    int orangeCount = 0;

    if (grid.empty()) return 0;

    memset(seen, false, sizeof(seen));

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) {
                orangeCount++;
            } else if (grid[i][j] == 2) {
                orangeCount++;
                seen[i][j] = true;
                queue.push(make_pair(i,j));
            }
        }
    }

    return orangeCount == 0 ? 0 : bfs(queue, orangeCount, grid);
}

int main() {
    vector<int> row00 {2,1,1};
    vector<int> row01 {1,1,0};
    vector<int> row02 {0,1,1};
    vector<vector<int>> grid0 {row00, row01, row02};

    vector<int> row10 {2,1,1};
    vector<int> row11 {0,1,1};
    vector<int> row12 {1,0,1};
    vector<vector<int>> grid1 {row10, row11, row12};

    vector<int> row20 {0,2};
    vector<vector<int>> grid2 {row20};

    int ans0 = orangesRotting(grid0);
    int ans1 = orangesRotting(grid1);
    int ans2 = orangesRotting(grid2);

    cout << ans0 << endl; // 4
    cout << ans1 << endl; // -1
    cout << ans2 << endl; // 0

    return 0;
}
