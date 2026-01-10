/* 209. Minimum Size Subarray Sum */
/** Given an array of n positive integers and a positive integer s, 
 *  find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 * 
 *  Example: 
 *  Input: s = 7, nums = [2,3,1,2,4,3]
 *  Output: 2
 *  Explanation: the subarray [4,3] has the minimal length under the problem constraint. **/

/* discussion에서 보고 알게된 sliding window를 이용한 풀이 */

#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

int minSubArrayLen(int s, vector<int> &nums) {
    int idx1 = 0;
    int idx2 = 0;
    int size = nums.size();
    int answer = INT_MAX;
    int sum;

    if (nums.empty()) return 0;
    sum = nums[0];

    while (true) {
        if (sum < s) {
            if (idx2 == size-1) break;
            idx2++;
            sum += nums[idx2];
        } else {
            answer = min(answer, idx2-idx1+1);
            sum -= nums[idx1];
            idx1++;
        }
    }

    return answer == INT_MAX ? 0 : answer;

}

int main() {
    vector<int> nums0 {2,3,1,2,4,3};
    int s0 = 7;
    int ans0 = minSubArrayLen(s0, nums0);

    vector<int> nums1 {1,4,4};
    int s1 = 4;
    int ans1 = minSubArrayLen(s1, nums1);

    cout << ans0 << endl; // 2
    cout << ans1 << endl; // 1

    return 0;
}

