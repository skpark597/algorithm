/* 560. Subarray Sum Equals K */
/** Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
 *  
 *  Example 1:
 *  Input: nums = [1,1,1], k = 2
 *  Output: 2
 * 
 *  Example 2:
 *  Input: nums = [1,2,3], k = 3
 *  Output: 2
 * 
 *  Constraints:
 *  1 <= nums.length <= 2 * 10^4
 *  -1000 <= nums[i] <= 1000
 *  -10^7 <= k <= 10^7 **/

/* discussion에서 참고해서 구현한 코드 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int subarraySum(vector<int> &nums, int k) {
    map<int,int> sums;
    int cur_sum = 0;
    int answer = 0;
    int complement;

    for (int i = 0; i < nums.size(); ++i) {
        cur_sum += nums[i];
        complement = cur_sum - k;

        if (complement == 0) answer++;
        if (sums.count(complement)) answer += sums[complement];
        
        if (sums.count(cur_sum)){
            sums[cur_sum]++;
        } else {
            sums[cur_sum] = 1;
        }
    }

    return answer;
}

int main() {
    vector<int> nums1 {1,1,1};
    int k1 = 2;

    vector<int> nums2 {1,2,3};
    int k2 = 3;

    int answer1 = subarraySum(nums1, k1);
    int answer2 = subarraySum(nums2, k2);

    cout << answer1 << endl;
    cout << answer2 << endl;

    return 0;
}