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

/* Discusstion에서 아이디어를 얻은 뒤 다시 내가 구현한 풀이 */

#include <iostream>
#include <iterator>
#include <vector>
#include <set>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    multiset<int> container;

    if (nums.empty() || nums.size() == 1 || k == 0) return false;

    container.insert(nums[0]);

    for (int i = 1; i < nums.size(); ++i) {
        auto lower_bound = container.lower_bound(nums[i]);
        auto previous = (lower_bound == container.begin()) ? container.end() : prev(lower_bound, 1);
        bool cond1 = false;
        bool cond2 = false;

        if (lower_bound != container.end()) {
            cond1 = (long)(*lower_bound) - (long)nums[i] <= t;
        }

        if (previous != container.end()) {
            cond2 = (long)nums[i] - (long)(*previous) <= t;
        }

        if (cond1 || cond2) return true;
        if (i >= k) container.erase(nums[i-k]);
        container.insert(nums[i]);
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