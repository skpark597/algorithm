/* 40. Combination Sum II */
/** Given a collection of candidate numbers (candidates) and a target number (target), 
 *  find all unique combinations in candidates where the candidate numbers sum to target.
 *  Each number in candidates may only be used once in the combination.
 * 
 *  Note: The solution set must not contain duplicate combinations.
 * 
 *  Example 1:
 *  Input: candidates = [10,1,2,7,6,1,5], target = 8
 *  Output: [[1,1,6], [1,2,5], [1,7], [2,6]]
 * 
 *  Example 2:
 *  Input: candidates = [2,5,2,1,2], target = 5
 *  Output: [[1,2,2], [5]]
 * 
 *  Constraints:
 *  1 <= candidates.length <= 100
 *  1 <= candidates[i] <= 50
 *  1 <= target <= 30 **/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> collections;
int targetNumber;

void backTracking(vector<vector<int>> &answer, vector<int> &cases, int index, int sum) {
    if (sum == targetNumber) {
        vector<int> newCase = cases;
        sort(newCase.begin(), newCase.end());
        
        for (int i = 0; i < answer.size(); ++i) {
            if (answer[i] == newCase) return;
        }
        answer.push_back(newCase);
        return;
    } else if (sum > targetNumber || index == collections.size()) {
        return;
    }

    backTracking(answer, cases, index+1, sum);
    cases.push_back(collections[index]);
    backTracking(answer, cases, index+1, sum + collections[index]);
    cases.pop_back();
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> answer;
    vector<int> cases;
    collections = candidates;
    targetNumber = target;
    backTracking(answer, cases, 0, 0);
    return answer;
}

int main() {
    vector<int> candidate0 {10,1,2,7,6,1,5};
    vector<int> candidate1 {2,5,2,1,2};

    vector<vector<int>> ans0 = combinationSum2(candidate0, 8);
    vector<vector<int>> ans1 = combinationSum2(candidate1, 5);

    for (vector<int> iter0 : ans0) {
        cout << "[ ";
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        }
        cout << "], ";
    } // [[1,1,6], [1,2,5], [1,7], [2,6]]

    cout << endl;
    for (vector<int> iter0 : ans1) {
        cout << "[ ";
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        }
        cout << "], ";
    } // [[1,2,2], [5]]

    return 0;
}