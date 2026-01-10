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

int cache[100];

int rob(vector<int> &nums) {
    int answer;
    memset(cache, -1 , sizeof(cache));

    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);

    // include first house, exclude last house
    cache[0] = nums[0];
    cache[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size()-1; ++i) {
        cache[i] = max(cache[i-2]+nums[i], cache[i-1]);
    }

    answer = cache[nums.size()-2];

    // exclude first house, include last house
    cache[0] = 0;
    cache[1] = nums[1];

    for (int i = 2; i < nums.size(); ++i) {
        cache[i] = max(cache[i-2]+nums[i], cache[i-1]);
    }

    answer = max(answer, cache[nums.size()-1]);

    return answer;
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