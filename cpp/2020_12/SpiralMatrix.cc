/* 54. Spiral Matrix */
/** Given an m x n matrix, return all elements of the matrix in spiral order.
 *  
 *  Example 1:
 *  Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 *  Output: [1,2,3,6,9,8,7,4,5]
 * 
 *  Example 2:
 *  Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 *  Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 *  Constraints:
 *  m == matrix.length
 *  n == matrix[i].length
 *  1 <= m, n <= 10
 *  -100 <= matrix[i][j] <= 100 **/

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

bool visited[10][10];
vector<int> dx {0, 1, 0, -1};
vector<int> dy {1, 0, -1, 0};

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> answer;
    int direction = 0;
    int x = 0;
    int y = 0;
    int next_x, next_y;
    int width, height;

    if (matrix.empty()) return vector<int>();
    
    width = matrix[0].size();
    height = matrix.size();
    memset (visited, false, sizeof(visited));

    for (int i = 0 ; i < height * width; ++i) {
        visited[x][y] = true;
        answer.push_back(matrix[x][y]);

        next_x = x + dx[direction];
        next_y = y + dy[direction];

        if (next_x < 0 || next_x > height-1 || next_y < 0 || next_y > width-1 || visited[next_x][next_y]) {
            direction = (direction + 1) % 4;
            x = x + dx[direction];
            y = y + dy[direction];
        } else {
            x = next_x;
            y = next_y;
        }
    }

    return answer;
}

int main() {
    vector<int> r11 {1,2,3};
    vector<int> r12 {4,5,6};
    vector<int> r13 {7,8,9};
    vector<vector<int>> matrix1 {r11, r12, r13};

    vector<int> ans1 = spiralOrder(matrix1);

    vector<int> r21 {1,2,3,4};
    vector<int> r22 {5,6,7,8};
    vector<int> r23 {9,10,11,12};

    vector<vector<int>> matrix2 {r21, r22, r23};

    vector<int> ans2 = spiralOrder(matrix2);

    for (int i = 0; i < ans1.size(); ++i) {
        cout << ans1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < ans2.size(); ++i) {
        cout << ans2[i] << " ";
    }
    cout << endl;

    return 0;
}
