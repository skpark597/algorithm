/* 213. House Robber II */
/** You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
 *  All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, 
 *  adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * 
 *  Given a list of non-negative integers nums representing the amount of money of each house, 
 *  return the maximum amount of money you can rob tonight without alerting the police.
 *  
 *  Example 1:
 *  Input: nums = [2,3,2]
 *  Output: 3
 *  Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
 * 
 *  Example 2:
 *  Input: nums = [1,2,3,1]
 *  Output: 4
 *  Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *  Total amount you can rob = 1 + 3 = 4.
 * 
 *  Example 3:
 *  Input: nums = [0]
 *  Output: 0
 * 
 *  Constraints:
 *  1 <= nums.length <= 100
 *  0 <= nums[i] <= 1000 **/

/* 내가 처음 생각한 풀이. 이것도 괜찮다고 생각한다. */

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int cache[100][2];

int maxMoney (vector<int> &nums, int index, int firstSelected) {
    int cand1, cand2;

    if (index == nums.size()-1) {
        return firstSelected ? 0 : nums[index];
    } else if (index > nums.size()-1) {
        return 0;
    }

    int &ret = cache[index][firstSelected];

    if (ret != -1) return ret;

    cand1 = nums[index] + maxMoney(nums, index+2, firstSelected);
    cand2 = maxMoney(nums, index+1, firstSelected);

    ret = max(cand1, cand2);
    
    return ret;
}

int rob(vector<int> &nums) {
    int cand1, cand2;
    if (nums.empty()) return 0;

    memset(cache, -1, sizeof(cache));
    cand1 = nums[0] + maxMoney(nums, 2, true); 
    cand2 = maxMoney(nums, 1, false);

    return max(cand1, cand2);
}

int main() {
    vector<int> nums0 {2,3,2};
    int ans0 = rob(nums0);

    vector<int> nums1 {1,2,3,1};
    int ans1 = rob(nums1);
    
    vector<int> nums2 {0};
    int ans2 = rob(nums2);

    vector<int> nums3 {1,3,1,3,100};
    int ans3 = rob(nums3);
    
    cout << ans0 << endl; // 3
    cout << ans1 << endl; // 4
    cout << ans2 << endl; // 0
    cout << ans3 << endl; // 103

    return 0;
}

