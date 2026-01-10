/* 287. Find the Duplicate Number */
/** Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 *  There is only one repeated number in nums, return this repeated number.
 * 
 *  Example 1:
 *  Input: nums = [1,3,4,2,2]
 *  Output: 2
 * 
 *  Example 2:
 *  Input: nums = [3,1,3,4,2]
 *  Output: 3
 * 
 *  Example 3:
 *  Input: nums = [1,1]
 *  Output: 1
 * 
 *  Example 4:
 *  Input: nums = [1,1,2]
 *  Output: 1
 * 
 *  Constraints:
 *  2 <= n <= 3 * 10^4
 *  nums.length == n + 1
 *  1 <= nums[i] <= n
 *  All the integers in nums appear only once except for precisely one integer which appears two or more times.
 * 
 *  Follow up:
 *  How can we prove that at least one duplicate number must exist in nums?
 *  Can you solve the problem without modifying the array nums?
 *  Can you solve the problem using only constant, O(1) extra space?
 *  Can you solve the problem with runtime complexity less than O(n^2)? **/

#include <vector>
#include <set>
#include <algorithm>
#include <stdlib.h>

using namespace std;

vector<int> findDuplicate (vector<int> &nums) {
    set<int> search_tree;
    vector<int> answer;
    
    for (int &iter : nums) {
        if (search_tree.count(iter)) answer.push_back(iter);
        else search_tree.insert(iter);
    }

    std::sort(answer.begin(), answer.end());
    return answer;
}

vector<int> findDuplicate2 (vector<int> &nums) {
    vector<int> answer;

    for (int i=0; i < nums.size(); ++i) {
        if (nums[abs(nums[i])-1] > 0 ) nums[abs(nums[i])-1] *= -1;
        else answer.push_back(abs(nums[i]));
    }
    
    return answer;
}


int main() {
    vector<int> nums {4,3,2,7,8,2,3,1};
    findDuplicate2(nums);
    return 0;
}