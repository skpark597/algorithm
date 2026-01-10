/* 221. Maximal Square */
/** Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 *  
 *  Example 1:
 *  Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 *  Output: 4
 *  
 *  Example 2:
 *  Input: matrix = [["0","1"],["1","0"]]
 *  Output: 1
 * 
 *  Example 3:
 *  Input: matrix = [["0"]]
 *  Output: 0
 * 
 *  Constraints:
 *  m == matrix.length
 *  n == matrix[i].length
 *  1 <= m, n <= 300
 *  matrix[i][j] is '0' or '1' **/

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int sideLength[301][301];

int maximalSquare(vector<vector<char>> &matrix) {
    int answer = 0;
    int rows;
    int columns;

    if (matrix.empty()) return 0;

    memset(sideLength, 0, sizeof(sideLength));
    rows = matrix.size();
    columns = matrix[0].size();

    for (int i = rows-1; i >= 0; --i) {
        for (int j = columns-1; j >= 0; --j) {
            if (matrix[i][j] == '1') {
                sideLength[i][j] = min(min(sideLength[i][j+1]+1, sideLength[i+1][j]+1), sideLength[i+1][j+1]+1);
                answer = max(sideLength[i][j], answer);
            }
        }
    }

    return answer * answer;
}

int main() {
    vector<char> row00 {'1','0','1','0','0'};
    vector<char> row01 {'1','0','1','1','1'};
    vector<char> row02 {'1','1','1','1','1'};
    vector<char> row03 {'1','0','0','1','1'};
    vector<vector<char>> matrix0 {row00, row01, row02, row03};

    vector<char> row10 {'0','1'};
    vector<char> row11 {'1','0'};
    vector<vector<char>> matrix1 {row10, row11};

    vector<char> row20 {'0'};
    vector<vector<char>> matrix2 {row20};

    int ans0 = maximalSquare(matrix0);
    int ans1 = maximalSquare(matrix1);
    int ans2 = maximalSquare(matrix2);

    cout << ans0 << endl; // 4
    cout << ans1 << endl; // 1
    cout << ans2 << endl; // 0

    return 0;
}


