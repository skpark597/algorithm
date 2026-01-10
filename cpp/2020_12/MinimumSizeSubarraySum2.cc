/* 209. Minimum Size Subarray Sum */
/** Given an array of n positive integers and a positive integer s, 
 *  find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 * 
 *  Example: 
 *  Input: s = 7, nums = [2,3,1,2,4,3]
 *  Output: 2
 *  Explanation: the subarray [4,3] has the minimal length under the problem constraint. **/

/* 내가 처음 생각한 binary search를 이용한 풀이 */
#include <vector>
#include <iostream>

using namespace std;

int minSubArrayLen(int s, vector<int> &nums) {
    vector<int> sums;
    int size = nums.size();
    int left = 0;
    int right = size;
    int middle, sum;
    bool findSubArray;

    if (nums.empty()) return 0;

    sums.resize(size+1);
    sums[size] = 0;

    for (int i = size-1; i >= 0; --i) {
        sums[i] = sums[i+1] + nums[i];
    }

    while (left <= right) {
        findSubArray = false;
        middle = (left + right) / 2;
        sum = sums[size-middle];

        for (int i = size-middle; i >= 0; --i) {
            if (sum >= s) {
                findSubArray = true;
                break;
            }

            if (i == 0) break;
            sum += nums[i-1];
            sum -= nums[middle+i-1];
        }

        if (findSubArray) {
            right = middle-1;
        } else {
            left = middle+1;
        }
    }

    return left == size+1 ? 0 : left;
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

