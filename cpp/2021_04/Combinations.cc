/* 77. Combinations */
/** Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
 *  You may return the answer in any order.
 * 
 *  Example 1:
 *  Input: n = 4, k = 2
 *  Output:
 *  [
 *    [2,4],
 *    [3,4],
 *    [2,3],
 *    [1,2],
 *    [1,3],
 *    [1,4],
 *  ]
 * 
 *  Example 2:
 *  Input: n = 1, k = 1
 *  Output: [[1]]
 * 
 *  Constraints:
 *  1 <= n <= 20
 *  1 <= k <= n **/

#include <vector>
#include <iostream>

using namespace std;

void backTracking(vector<vector<int>> &answer, vector<int> &combination, int count, int cur, int n, int k) {
    if (count == k) {
        answer.push_back(combination);
        return;
    }

    if (cur > n) return;

    combination.push_back(cur);
    backTracking(answer, combination, count+1, cur+1, n, k);
    combination.pop_back();

    backTracking(answer, combination, count, cur+1, n, k);
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> answer;
    vector<int> combination;
    
    backTracking(answer, combination, 0, 1, n, k);

    return answer;
}

int main() {
    vector<vector<int>> ans0 = combine(4, 2);
    vector<vector<int>> ans1 = combine(1, 1);

    for (vector<int> iter0 : ans0) {
        cout << "[";
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        } cout << "] ";
    }

    cout << endl;

    for (vector<int> iter0 : ans1) {
        cout << "[";
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        } cout << "] ";
    }

    return 0;
}

