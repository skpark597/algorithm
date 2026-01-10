/* 378. Kth Smallest Element in a Sorted Matrix */
/** Given an n x n matrix where each of the rows and columns are sorted in ascending order, 
 *  return the kth smallest element in the matrix.
 *  
 *  Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 * 
 *  Example 1:
 *  Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 *  Output: 13
 *  Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
 * 
 *  Example 2:
 *  Input: matrix = [[-5]], k = 1
 *  Output: -5
 * 
 *  Constraints:
 *  n == matrix.length
 *  n == matrix[i].length
 *  1 <= n <= 300
 *  -10^9 <= matrix[i][j] <= -10^9
 *  All the rows and columns of matrix are guaranteed to be sorted in non-degreasing order.
 *  1 <= k <= n^2 **/

#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> pq;
    int size;

    if (matrix.empty()) return 0;
    size = matrix.size();

    for (int row = 0; row < min(k, size); ++row) {
        for (int col = 0; col < min(k-row, size); ++col) {
            pq.push(matrix[row][col]);
        }
    }

    while (pq.size() > k) pq.pop();

    return pq.top();
}

int main() {
    vector<int> row00 {1,5,9};
    vector<int> row01 {10,11,13};
    vector<int> row02 {12,13,15};
    vector<vector<int>> matrix0 {row00, row01, row02};

    vector<int> row10 {-5};
    vector<vector<int>> matrix1 {row10};

    vector<int> row20 {1,3,5};
    vector<int> row21 {6,7,12};
    vector<int> row22 {11,14,14};
    vector<vector<int>> matrix2 {row20, row21, row22};

    int ans0 = kthSmallest(matrix0, 8);
    int ans1 = kthSmallest(matrix1, 1);
    int ans2 = kthSmallest(matrix2, 3);

    cout << ans0 << endl; // 13
    cout << ans1 << endl; // -5
    cout << ans2 << endl; // 5

    return 0;
}

