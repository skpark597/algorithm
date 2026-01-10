/* 198. House Robber */
/** You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
 *  the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
 *  it will automatically contact the police if two adjacent houses were broken into on the same night.
 *  Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of 
 *  money you can rob tonight without alerting the police.
 * 
 *  Example 1:
 *  Input: nums = [1,2,3,1]
 *  Output: 4
 *  Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *               Total amount you can rob = 1 + 3 = 4.
 * 
 *  Example 2:
 *  Input: nums = [2,7,9,3,1]
 *  Output: 12
 *  Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 *               Total amount you can rob = 2 + 9 + 1 = 12.
 *  Constraints:
 *  0 <= nums.length <= 100
 *  0 <= nums[i] <= 400 **/

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int cache[101];

int maxMoney(vector<int> &nums, int index) {
    if (index > nums.size() - 1) return 0;

    int &money = cache[index];
    if (money != -1) return money;

    int cand1 = nums[index] + maxMoney(nums, index + 2);
    int cand2 = maxMoney(nums, index + 1);

    money = max(cand1, cand2);

    return money;
}

int rob(vector<int> &nums) {
    memset(cache, -1, sizeof(cache));
    return maxMoney(nums, 0);
}

int main() {
    vector<int> nums0 {1,2,3,1};
    vector<int> nums1 {2,7,9,3,1};

    int ans0 = rob(nums0);
    int ans1 = rob(nums1);

    cout << ans0 << endl; // 4
    cout << ans1 << endl; // 12

    return 0;
}


