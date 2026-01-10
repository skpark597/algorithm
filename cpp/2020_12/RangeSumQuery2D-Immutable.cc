/* 304. Range Sum Query 2D - Immutable */
/** Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its 
 *  upper left corner (row1, col1) and lower right corner (row2, col2).
 * 
 *  Range Sum Query 2D
 *  The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
 * 
 *  Example:
 *  Given matrix = [
 *  [3, 0, 1, 4, 2],
 *  [5, 6, 3, 2, 1],
 *  [1, 2, 0, 1, 5],
 *  [4, 1, 0, 1, 7],
 *  [1, 0, 3, 0, 5]
 *  ]
 * 
 *  sumRegion(2, 1, 4, 3) -> 8
 *  sumRegion(1, 1, 2, 2) -> 11
 *  sumRegion(1, 2, 2, 4) -> 12
 * 
 *  Note:
 *  You may assume that the matrix does not change.
 *  There are many calls to sumRegion function.
 *  You may assume that row1 ≤ row2 and col1 ≤ col2. **/

#include <vector>
#include <iostream>

using namespace std;

class NumMatrix {
public:
    int row;
    int col;
    vector<vector<int>> cache;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            row = 0;
            col = 0;
            return;
        }

        row = matrix.size();
        col = matrix[0].size();
        cache.resize(row+1);
        for (int i = 0; i <= row; ++i) {
            cache[i].resize(col+1, 0);
        }

        for (int i = row-1; i >= 0; --i) {
            for (int j = col-1; j >= 0; --j) {
                cache[i][j] = matrix[i][j] + cache[i][j+1] + cache[i+1][j]-cache[i+1][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return cache[row1][col1] - cache[row2+1][col1] - cache[row1][col2+1] + cache[row2+1][col2+1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    vector<int> row01 {3,0,1,4,2};
    vector<int> row02 {5,6,3,2,1};
    vector<int> row03 {1,2,0,1,5};
    vector<int> row04 {4,1,0,1,7};
    vector<int> row05 {1,0,3,0,5};
    vector<vector<int>> matrix0 {row01, row02, row03, row04, row05};

    NumMatrix *obj0 = new NumMatrix(matrix0);
    int ans00 = obj0->sumRegion(2,1,4,3);
    int ans01 = obj0->sumRegion(1,1,2,2);
    int ans02 = obj0->sumRegion(1,2,2,4);

    cout << ans00 << endl; // 8
    cout << ans01 << endl; // 11
    cout << ans02 << endl; // 12
    
    return 0;
}

