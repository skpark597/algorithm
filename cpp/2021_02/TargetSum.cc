/** 494. Target Sum */
/** You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
 *  Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
 *  Find out how many ways to assign symbols to make sum of integers equal to target S.
 * 
 *  Example 1:
 *  Input: nums is [1, 1, 1, 1, 1], S is 3. 
 *  Output: 5
 * 
 *  Explanation: 
 *  -1+1+1+1+1 = 3
 *  +1-1+1+1+1 = 3
 *  +1+1-1+1+1 = 3
 *  +1+1+1-1+1 = 3
 *  +1+1+1+1-1 = 3
 *  There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 *  Constraints:
 *  The length of the given array is positive and will not exceed 20.
 *  The sum of elements in the given array will not exceed 1000.
 *  Your output answer is guaranteed to be fitted in a 32-bit integer. **/

// dfs는 내가 처음 생각한 풀이. 

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int dp[1000];

int subsetSum(vector<int> &nums, int s) {
    for (int num : nums) {
        for (int i = s; i >= num; --i) {
            dp[i] += dp[i-num];
        }
    }

    return dp[s];
}

void dfs(vector<int> &nums, int index, int sum, int S, int &answer) {
    if (index == nums.size()) {
        if (sum == S) answer++;
        return;
    }

    dfs(nums, index+1, sum-nums[index], S, answer);
    dfs(nums, index+1, sum+nums[index], S, answer);
}

int findTargetSumWays(vector<int> &nums, int S) {
    int sum = 0;
    
    memset(dp, 0 , sizeof(dp));
    dp[0] = 1;
    for (int num : nums) sum += num;

    return sum < S || (sum + S) % 2 == 1 ? 0 : subsetSum(nums, (sum+S) / 2);

    //dfs(nums, 0, 0, S, answer);
    //return answer;
}

int main() {
    vector<int> nums0 {1,1,1,1,1};
    int ans0 = findTargetSumWays(nums0, 3);

    cout << ans0 << endl; // 5

    return 0;
}

