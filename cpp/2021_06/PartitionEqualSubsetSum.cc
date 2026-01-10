/** 416. Partition Equal Subset Sum */
/** Given a non-empty array nums containing only positive integers, \
 *  find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
 * 
 *  Example 1:
 *  Input: nums = [1,5,11,5]
 *  Output: true
 *  Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 *  Example 2:
 *  Input: nums = [1,2,3,5]
 *  Output: false
 *  Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 *  Constraints:
 *  1 <= nums.length <= 200
 *  1 <= nums[i] <= 100 */

#include <vector>
#include <iostream>

using namespace std;

// 초기 상태 -1, FALSE 0, TRUE 1
int cache[201][20001];
    
bool canMakeSum(vector<int> &nums, int start, int target) {
    if (target < 0) return false;
    if (target == 0) return true;

    int &ret = cache[start][target];
    if (ret != -1) return ret;
    if (start == nums.size()-1) return target == nums.back();        
        
    ret = canMakeSum(nums, start+1, target-nums[start]);
    ret |= canMakeSum(nums, start+1, target);
        
    return ret;
}
    
void init() {
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 20001; ++j) {
            cache[i][j] = -1;
        }
    }
}
    
bool canPartition(vector<int> &nums) {
    int target = 0;
    int total = 0;
    
    init();
    for (int iter : nums) total += iter;
    
    if (total % 2 != 0) return false;
    target = total / 2;
    
    return canMakeSum(nums, 0, target);
}

int main() {
    vector<int> nums0 {1,5,11,5};
    vector<int> nums1 {1,2,3,5};
    vector<int> nums2 {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97};

    bool ans0 = canPartition(nums0);
    bool ans1 = canPartition(nums1);

    int size = nums2.size();

    cout << ans0 << endl; // true
    cout << ans1 << endl; // false

    return 0;
}
