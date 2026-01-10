/* 47. PermutationsII */
/** Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
 *  Example 1:
 *  Input: nums = [1,1,2]
 *  Output: [[1,1,2], [1,2,1], [2,1,1]]
 * 
 *  Example 2:
 *  Input: nums = [1,2,3]
 *  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 *  Constraints:
 *  1 <= nums.length <= 8
 *  -10 <= nums[i] <= 10 **/

/* counts와 newNums를 인자로 넘기면 counts를 매번 계산안해도 될 것으로 보임. backtracking으로 개선해보자*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> counts;

vector<vector<int>> addNumber (vector<vector<int>> &nums) {
    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); ++i) {
        vector<int> currentCounts = counts;

        for (int j = 0; j < nums[i].size(); ++j) {
            currentCounts[nums[i][j]+10]--;
        }

        for (int j = -10; j <= 10; ++j) {
            vector<int> newNums = nums[i];
            if (currentCounts[j+10] == 0) continue;
            newNums.push_back(j);
            result.push_back(newNums);
        }
    }

    return result;
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> answer;
    vector<int> start;

    counts.resize(21,0);
    answer.push_back(start);

    for (int i = 0; i < nums.size(); ++i) {
        counts[nums[i]+10]++;
    }

    for (int i = 0; i < nums.size(); ++i) {
        answer = addNumber(answer);
    }

    return answer;
}

int main() {
    vector<int> nums;
    //nums.push_back(1);
    //nums.push_back(2);
    //nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);

    vector<vector<int>> answer = permuteUnique(nums);

    for (int i = 0; i < answer.size(); ++i) {
        for (int j = 0; j < answer[i].size(); ++j) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


