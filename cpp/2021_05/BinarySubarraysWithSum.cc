/** 930. Binary Subarrays With Sum */
/** In an array nums of 0s and 1s, how many non-empty subarrays have sum goal?
 * 
 *  Example 1:
 *  Input: nums = [1,0,1,0,1], goal = 2
 *  Output: 4
 *  The 4 subarrays are bolded below:
 *  [1,0,1,0,1]
 *  [1,0,1,0,1]
 *  [1,0,1,0,1]
 *  [1,0,1,0,1]
 * 
 *  Note:
 *  nums.length <= 30000
 *  0 <= goal <= nums.length
 *  nums[i] is either 0 or 1. **/

#include <vector>
#include <iostream>

using namespace std;

int numberOfSubArray0(vector<int> &zeroCount) {
    int answer = 0;

    for (int i = 0 ; i < zeroCount.size(); ++i) {
        answer += zeroCount[i] * (zeroCount[i] + 1) /2;
    }

    return answer;
}

int numberOfSubArray1(vector<int> &zeroCount, int goal) {
    int answer = 0;

    for (int i = 0; i < zeroCount.size()-goal; ++i) {
        answer += (zeroCount[i]+1) * (zeroCount[i+goal]+1);
    }

    return answer;
}

int numSubarraysWithSum(vector<int> &nums, int goal) {
    int answer = 0;
    int count = 0;
    vector<int> zeroCount;

    if (goal < 0) return 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            count++;
        } else {
            zeroCount.push_back(count);
            count = 0;
        }
    }

    zeroCount.push_back(count);
    return goal == 0 ? numberOfSubArray0(zeroCount) : numberOfSubArray1(zeroCount, goal);
}

int main() {
    vector<int> nums0 {1,0,1,0,1};
    int ans0 = numSubarraysWithSum(nums0, 2);

    vector<int> nums1 {0,0,0,0,0};
    int ans1 = numSubarraysWithSum(nums1, 0);

    vector<int> nums2 {1,1,0,1,0,0,1};
    int ans2 = numSubarraysWithSum(nums2, 2);

    vector<int> nums3 {1,1,0,1,0,0,1};
    int ans3 = numSubarraysWithSum(nums3, 0);

    vector<int> nums4 {0,0,0,0,1};
    int ans4 = numSubarraysWithSum(nums4, 2);

    vector<int> nums5 {0,1,1,1,1};
    int ans5 = numSubarraysWithSum(nums5, 3);

    cout << ans0 << endl; // 4
    cout << ans1 << endl; // 15
    cout << ans2 << endl; // 7
    cout << ans3 << endl; // 4
    cout << ans4 << endl; // 0
    cout << ans5 << endl; // 3

    return 0;
}
