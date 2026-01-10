/** 46. Permutations */
/** Given an array nums of distinct integers, return all the possible permutations. 
 *  You can return the answer in any order.
 * 
 *  Example 1:
 *  Input: nums = [1,2,3]
 *  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 *  Example 2:
 *  Input: nums = [0,1]
 *  Output: [[0,1],[1,0]] 
 * 
 *  Example 3:
 *  Input: nums = [1]
 *  Output: [[1]]
 * 
 *  Constraints:
 *  1 <= nums.length <= 6
 *  -10 <= nums[i] <= 10
 *  All the integers of nums are unique. **/

#include <vector>
#include <set>
#include <cstring>
#include <iostream>

using namespace std;

void makePermutation(vector<vector<int>> &answer, vector<int> &nums, int used, vector<int> &permutation) {
    if (permutation.size() == nums.size()) {
        answer.push_back(permutation);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        int newUsed = used;
        if (used & (1 << i)) continue;
        permutation.push_back(nums[i]);
        newUsed |= (1 << i);
        makePermutation(answer, nums, newUsed, permutation);
        permutation.pop_back();
    }

}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> answer;
    int used = 1 << nums.size();
    vector<int> permutation;

    makePermutation(answer, nums, used, permutation);

    return answer;
}

int main() {
    vector<int> nums0 {1,2,3};
    vector<int> nums1 {0,1};
    vector<int> nums2 {1};

    vector<vector<int>> ans0 = permute(nums0);
    vector<vector<int>> ans1 = permute(nums1);
    vector<vector<int>> ans2 = permute(nums2);

    for (vector<int> iter0 : ans0) {
        cout << "[";
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        } cout << "] ";
    } // [1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]
    cout << endl;
 
    for (vector<int> iter0 : ans1) {
        cout << "[";
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        } cout << "] ";
    } // [0,1],[1,0]
    cout << endl;

    for (vector<int> iter0 : ans2) {
        cout << "[";
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        } cout << "] ";
    } // [1]
    cout << endl;

    return 0;
}
