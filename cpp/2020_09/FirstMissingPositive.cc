/* 41. First Missing Positive */ 
/** Given an unsorted integer array, find the smallest missing positive integer. 
 *  Example 1:
 *  Input: [1,2,0]
 *  Output: 3
 *  
 *  Example 2:
 *  Input: [3,4,-1,1]
 *  Output: 2
 *  
 *  Example 3:
 *  Input: [7,8,9,11,12]
 *  Output: 1
 *  Follow up: Your algorithm should run in O(n) time and uses constant extra space. 
 * 
 *  Hide Hint #1 : Think about how you would solve the problem in non-constant space. Can you apply that logic to the existing space?
 *  Hide Hint #2 : We don't care about duplicates or non-positive integers
 *  Hide Hint #3 : Remember that O(2n) = O(n) **/

#include <vector>
#include <iostream>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    bool oneExist = false;
    int size = nums.size();
    int index;

    for (int i=0; i < size; ++i) {
        if (nums[i] == 1) { oneExist = true;}
        if (nums[i] <= 0 || nums[i] > size) { nums[i] = 1; }
    }

    if (!oneExist) return 1;

    for (int i=0; i < size; ++i) {
        index = abs(nums[i])-1;
        if (nums[index] > 0) { nums[index] *= -1;}
    }

    for (int i=0; i<size; ++i) {
        if (nums[i] > 0) return i+1;
    }

    return size+1;
}

int main() {
    vector<int> nums {7,8,9,11,12};
    int answer = firstMissingPositive(nums);

    cout << answer << endl;
    return 0;
}

