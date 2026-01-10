/* 1524. Number of Sub-arrays With Odd Sum */
/** Given an array of integers arr. Return the number of sub-arrays with odd sum.
 *  As the answer may grow large, the answer must be computed modulo 10^9 + 7.
 * 
 *  Example 1:
 *  Input: arr = [1,3,5]
 *  Output: 4
 *  Explanation: All sub-arrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
 *  All sub-arrays sum are [1,4,9,3,8,5].
 *  Odd sums are [1,9,3,5] so the answer is 4.
 * 
 *  Example 2:
 *  Input: arr = [2,4,6]
 *  Output: 0
 *  Explanation: All sub-arrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
 *  All sub-arrays sum are [2,6,12,4,10,6].
 *  All sub-arrays have even sum and the answer is 0.
 * 
 *  Example 3:
 *  Input: arr = [1,2,3,4,5,6,7]
 *  Output: 16
 * 
 *  Example 4:
 *  Input: arr = [100,100,99,99]
 *  Output: 4
 * 
 *  Example 5:
 *  Input: arr = [7]
 *  Output: 1
 * 
 *  Constraints:
 *  1 <= arr.length <= 10^5
 *  1 <= arr[i] <= 100 **/

#include <vector>
#include <iostream>

using namespace std;

const int NUM = 1000000007;

int numOfSubarrays(vector<int> &arr) {
    int answer = 0;
    int oddCount = 0;
    int evenCount = 0;
    int oddBackup;

    if (arr.empty()) return 0;

    for (int i = arr.size()-1; i >= 0; --i) {
        if (arr[i] % 2 == 0) {
            oddCount = oddCount;
            evenCount = evenCount + 1;
        } else {
            oddBackup = oddCount;
            oddCount = evenCount + 1;
            evenCount = oddBackup;
        }

        answer += oddCount;
        answer %= NUM;
    }

    return answer;
}

int main() {
    vector<int> case0 {1,3,5};
    vector<int> case1 {2,4,6};
    vector<int> case2 {1,2,3,4,5,6,7};
    vector<int> case3 {100,100,99,99};
    vector<int> case4 {7};

    int answer0 = numOfSubarrays(case0);
    int answer1 = numOfSubarrays(case1);
    int answer2 = numOfSubarrays(case2);
    int answer3 = numOfSubarrays(case3);
    int answer4 = numOfSubarrays(case4);

    cout << answer0 << endl;  // 4
    cout << answer1 << endl;  // 0
    cout << answer2 << endl;  // 16
    cout << answer3 << endl;  // 4
    cout << answer4 << endl;  // 1

    return 0;
}




