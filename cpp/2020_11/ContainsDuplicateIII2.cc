/* 220. Contains Duplicate III */
/** Given an array of integers, find out whether there are two distinct indices i and j in the array 
 *  such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference 
 *  between i and j is at most k.
 * 
 *  Example 1:
 *  Input: nums = [1,2,3,1], k = 3, t = 0
 *  Output: true
 * 
 *  Example 2:
 *  Input: nums = [1,0,1,1], k = 1, t = 2
 *  Output: true
 * 
 *  Example 3:
 *  Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 *  Output: false
 * 
 *  Constraints:
 *  0 <= nums.length <= 2 * 10^4
 *  -2^31 <= nums[i] <= 2^31 - 1
 *  0 <= k <= 10^4
 *  0 <= t <= 2^31 - 1 **/

#include <iostream>
#include <vector>

/* 처음에 내가 시도했던 풀이. brute force를 이용했으나 시간초과로 실패함 */

using namespace std;

bool lessThanT (int num1, int num2, int t) {
    long long l1 = num1;
    long long l2 = num2;

    if (l1 >= l2) {
        return l1-l2 <= t;
    }

    return l2-l1 <= t;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int minimum = min(k, (int)(nums.size()-1));

    for (int i = 0; i < minimum; ++i) {
        for (int j = i + 1; j < minimum; ++j) {
            if (lessThanT(nums[i],nums[j],t)) return true;
        }
    }

    for (int i = minimum; i < nums.size(); ++i) {
        int start = max(i-k, 0);
        for (int j = start; j <= i-1; ++j) {
            if (lessThanT(nums[i],nums[j],t)) return true;
        }
    }

    return false;
}

int main() {
    vector<int> nums1 {1,2,3,1};
    vector<int> nums2 {1,0,1,1};
    vector<int> nums3 {1,5,9,1,5,9};
    vector<int> nums4 {1,2,1,1};
    vector<int> nums5 {1,2,2,3,4,5};
    vector<int> nums6 {-2147483648,2147483647};

    bool answer1 = containsNearbyAlmostDuplicate(nums1, 3, 0);
    bool answer2 = containsNearbyAlmostDuplicate(nums2, 1, 2);
    bool answer3 = containsNearbyAlmostDuplicate(nums3, 2, 3);
    bool answer4 = containsNearbyAlmostDuplicate(nums4, 1, 0);
    bool answer5 = containsNearbyAlmostDuplicate(nums5, 3, 0);
    bool answer6 = containsNearbyAlmostDuplicate(nums6, 1, 1);

    cout << answer1 << endl;
    cout << answer2 << endl;
    cout << answer3 << endl;
    cout << answer4 << endl;
    cout << answer5 << endl;
    cout << answer6 << endl;

    return 0;
}