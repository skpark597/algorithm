/* 673. Number of Longest Increasing Subsequence */
/** Given an integer array nums, return the number of longest increasing subsequences.
 * 
 *  Example 1:
 *  Input: nums = [1,3,5,4,7]
 *  Output: 2
 *  Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
 *  
 *  Example 2:
 *  Input: nums = [2,2,2,2,2]
 *  Output: 5
 *  Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
 * 
 *  Constraints:
 *  0 <= nums.length <= 2000
 *  -106 <= nums[i] <= 106 **/

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

pair<int, int> cache[2001];

pair<int,int> numberOfLIS(vector<int> &nums, int start) {
    pair<int,int> &ret = cache[start];
    int &count = cache[start].first;
    int &length = cache[start].second;

    if (count != -1) return ret;

    count = 1;
    length = 1;

    if (start == nums.size()-1) {
        return ret;
    }

    for (int i = start+1; i < nums.size(); ++i) {
        if (nums[start] < nums[i]) {
            pair<int,int> next = numberOfLIS(nums, i);
            if (length < next.second+1) {
                count = next.first;
                length = next.second+1;
            } else if (length == next.second+1) {
                count += next.first;
            }
        }
    }

    return ret;
}

int findNumberOfLIS(vector<int>& nums) {
    int count = 0;
    int length = 0;
    memset (cache, -1, sizeof(cache));

    for (int i = 0; i < nums.size(); ++i) {
        pair<int,int> ret = numberOfLIS(nums, i);

        if (length < ret.second) {
            count = ret.first;
            length = ret.second;
        } else if (length == ret.second) {
            count += ret.first;
        }
    }

    return count;
}

int main() {
    vector<int> nums {1,3,5,4,7};
    int answer = findNumberOfLIS(nums);

    cout << answer << endl;

    return 0;
}



