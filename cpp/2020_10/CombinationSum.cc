/* 39. Combination Sum */
/** Given an array of distinct integers candidates and a target integer target, 
 *  return a list of all unique combinations of candidates where the chosen numbers sum to target. 
 *  You may return the combinations in any order.
 *  The same number may be chosen from candidates an unlimited number of times. 
 *  Two combinations are unique if the frequency of at least one of the chosen numbers is different.
 * 
 *  Example 1:
 *  Input: candidates = [2,3,6,7], target = 7
 *  Output: [[2,2,3],[7]]
 *  Explanation:
 *  2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
 *  7 is a candidate, and 7 = 7.
 *  These are the only two combinations.
 *  
 *  Example 2:
 *  Input: candidates = [2,3,5], target = 8
 *  Output: [[2,2,2,2],[2,3,3],[3,5]]
 * 
 *  Example 3:
 *  Input: candidates = [2], target = 1
 *  Output: []
 * 
 *  Example 4:
 *  Input: candidates = [1], target = 1
 *  Output: [[1]]
 * 
 *  Example 5:
 *  Input: candidates = [1], target = 2
 *  Output: [[1,1]]
 * 
 *  Constraints:
 *  1 <= candidates.length <= 30
 *  1 <= candidates[i] <= 200
 *  All elements of candidates are distinct.
 *  1 <= target <= 500 **/

/** discussion에 나와있는 backtracking algorithm을 이용하여 해결 **/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void backTracking (vector<vector<int>> &result, vector<int> &candidates, vector<int> &combinations, 
                   int target, int begin) {
    if (target == 0) {
        result.push_back(combinations);
        return;
    }

    for (int i=begin; i < candidates.size(); ++i) {
        if (candidates[i] > target) continue;
        combinations.push_back(candidates[i]);
        backTracking (result, candidates, combinations, target-candidates[i], i);
        combinations.pop_back();
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combinations;
    sort(candidates.begin(), candidates.end());
    backTracking(result, candidates, combinations, target, 0);
    return result;
}

int main() {
    vector<int> candidates {2,3,6,7};
    int target = 7;
    vector<vector<int>> answer = combinationSum(candidates, target);

    for (int i=0; i < answer.size(); ++i) {
        for (int j=0; j < answer[i].size(); ++j) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}










