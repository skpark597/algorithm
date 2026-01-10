/* 861. Score After Flipping Matrix */
/** We have a two dimensional matrix A where each value is 0 or 1.
 *  A move consists of choosing any row or column, and toggling each value in that row or column: 
 *  changing all 0s to 1s, and all 1s to 0s.
 *  After making any number of moves, every row of this matrix is interpreted as a binary number, 
 *  and the score of the matrix is the sum of these numbers.
 * 
 *  Return the highest possible score.
 *  Example 1:
 *  Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 *  Output: 39
 *  Explanation:
 *  Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
 *  0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 *  
 *  Note:
 *  1 <= A.length <= 20
 *  1 <= A[0].length <= 20
 *  A[i][j] is 0 or 1. **/

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

void filpingColumn(vector<vector<int>> &A, int index) {
    for (int i = 0; i < A.size(); ++i) {
        A[i][index] = (A[i][index]+1) % 2;
    }
}

void flipingRow(vector<vector<int>> &A, int index) {
    for (int i = 0; i < A[0].size(); ++i) {
        A[index][i] = (A[index][i]+1) % 2;
    }
}

int matrixScore(vector<vector<int>> &A) {
    int answer = 0;
    int rowSize = A.size();
    int columnSize;
    int zeroCount;

    if (A.empty()) return 0;

    columnSize = A[0].size();

    for (int i = 0; i < rowSize; ++i) {
        if (A[i][0] == 0) flipingRow(A, i);
    }

    for (int i = 1; i < columnSize; ++i) {
        zeroCount = 0;
        for (int j = 0; j < rowSize; ++j) {
            if (A[j][i] == 0) zeroCount++;
        }

        if (zeroCount > rowSize / 2) filpingColumn(A, i);
    }

    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < columnSize; ++j) {
            answer += A[i][j] * pow(2, columnSize-j-1);
        }
    }
    
    return answer;
}

int main() {
    vector<int> row00 {0,0,1,1};
    vector<int> row01 {1,0,1,0};
    vector<int> row02 {1,1,0,0};
    vector<vector<int>> matrix0 {row00, row01, row02};

    int ans0 = matrixScore(matrix0);

    cout << ans0 << endl; // 39

    return 0;
}



