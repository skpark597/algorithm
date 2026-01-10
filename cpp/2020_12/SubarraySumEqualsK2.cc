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

/* Test Case를 모두 통과하지만 시간 초과로 실패한 코드 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int sum[20001];

int subarraySum(vector<int> &nums, int k) {
    int answer = 0;
    int size = nums.size();

    if (nums.size() == 1) return nums[0] == k ? 1 : 0;

    memset(sum, -1, sizeof(sum));
    sum[size] = 0;

    for (int i = size-1; i >= 0; --i) {
        sum[i] = sum[i+1] + nums[i];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = i+1; j <= size; ++j) {
            if (sum[i]-sum[j] == k) answer++;
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

