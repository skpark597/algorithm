/** 870. Advantage Shuffle */
/** Given two arrays nums1 and nums2 of equal size, the advantage of nums1 with respect to nums2 
 *  is the number of indices i for which nums1[i] > nums2[i].
 * 
 *  Return any permutation of nums1 that maximizes its advantage with respect to nums2.
 * 
 *  Example 1:
 *  Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
 *  Output: [2,11,7,15]
 * 
 *  Example 2:
 *  Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
 *  Output: [24,32,8,12]
 * 
 *  Note:
 *  1 <= nums1.length = nums2.length <= 10000
 *  0 <= nums1[i] <= 10^9
 *  0 <= nums2[i] <= 10^9 **/

#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool used[10000];

int findAdvantage(vector<int> &nums, int num) {
    auto upper = upper_bound(nums.begin(), nums.end(), num);
    int index = distance(nums.begin(), upper);

    for (int i = index; i < nums.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            return nums[i];
        }
    }

    for (int i = 0; i < index; ++i) {
        if (!used[i]) {
            used[i] = true;
            return nums[i];
        }
    }
}

vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
    vector<int> answer(nums2.size(), -1);
    memset(used, false, sizeof(used));
    sort(nums1.begin(), nums1.end());

    for (int i = 0; i < nums2.size(); ++i) {
        int advantage = findAdvantage(nums1, nums2[i]);
        if (advantage != -1) answer[i] = advantage;
    }

    return answer;
}

int main() {
    vector<int> nums01 {2,7,11,15};
    vector<int> nums02 {1,10,4,11};

    vector<int> nums11 {12,24,8,32};
    vector<int> nums12 {13,25,32,11};

    vector<int> ans0 = advantageCount(nums01, nums02);
    vector<int> ans1 = advantageCount(nums11, nums12);

    for (int iter : ans0)  cout << iter << " ";
    cout << endl; // 2 11 7 15

    for (int iter : ans1)  cout << iter << " ";
    cout << endl; // 24 32 8 12

    return 0;
}

