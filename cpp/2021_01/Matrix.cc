/* 01 Matrix */
/** Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
 *  The distance between two adjacent cells is 1.
 *  
 *  Example 1:
 *  Input:
 *  [[0,0,0],
 *   [0,1,0],
 *   [0,0,0]]
 *  Output:
 *  [[0,0,0],
 *   [0,1,0],
 *   [0,0,0]]
 * 
 *  Example 2:
 *  Input:
 *  [[0,0,0],
 *   [0,1,0],
 *   [1,1,1]]
 *  Output:
 *  [[0,0,0],
 *   [0,1,0],
 *   [1,2,1]]
 * 
 *  Note:
 *  The number of elements of the given matrix will not exceed 10000.
 *  There are at least one 0 in the given matrix.
 *  The cells are adjacent in only four directions: up, down, left and right. **/

/* discussion을 참고하여 풀었음 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// left, right, up, down
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

void init(vector<vector<int>> &matrix, vector<vector<int>> &answer, queue<pair<int,int>> &queue) {
    answer.resize(matrix.size());
    for (int i = 0; i < answer.size(); ++i) {
        answer[i].resize(matrix[0].size());
    }

    for (int i = 0; i < answer.size(); ++i) {
        for (int j = 0; j < answer[0].size(); ++j) {
            if (matrix[i][j] == 1) {
                answer[i][j] = INT_MAX;
            } else {
                answer[i][j] = 0;
                queue.push({i,j});
            }
        }
    }
}

vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
    queue<pair<int,int>> queue;
    vector<vector<int>> answer;

    if (matrix.empty()) return vector<vector<int>>();

    init(matrix, answer, queue);

    while (!queue.empty()) {
        int row = queue.front().first;
        int col = queue.front().second;
        queue.pop();

        for (int i = 0; i < 4; ++i) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if (new_row < 0 || new_row >= answer.size() || new_col < 0 || 
                new_col >= answer[0].size() || answer[new_row][new_col] <= answer[row][col] + 1) continue;

            answer[new_row][new_col] = answer[row][col] + 1;
            queue.push({new_row, new_col});
        }
    }

    return answer;
}

int main() {
    vector<int> row00 {0,0,0};
    vector<int> row01 {0,1,0};
    vector<int> row02 {0,0,0};
    vector<vector<int>> matrix0 {row00, row01, row02};

    vector<int> row10 {0,0,0};
    vector<int> row11 {0,1,0};
    vector<int> row12 {1,1,1};
    vector<vector<int>> matrix1 {row10, row11, row12};

    vector<vector<int>> ans0 = updateMatrix(matrix0);
    vector<vector<int>> ans1 = updateMatrix(matrix1);

    for (int i = 0; i < ans0.size(); ++i) {
        for (int j = 0; j < ans0[0].size(); ++j) {
            cout << ans0[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < ans1.size(); ++i) {
        for (int j = 0; j < ans1[0].size(); ++j) {
            cout << ans1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}


