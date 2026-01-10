#include <vector>
#include <iostream>

/* 229. Majority Element II */
/** Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 *  Note: The algorithm should run in linear time and in O(1) space.
 * 
 *  Example 1:
 *  Input: [3,2,3]
 *  Output: [3]
 *  
 *  Example 2:
 *  Input: [1,1,1,3,3,2,2,2]
 *  Output: [1,2] **/
// 결국 못풀어서 Discusstion 봄
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
        // support variables
        int cand1, vote1 = 0, cand2, vote2 = 0, lmt = nums.size() / 3;
        // looking for the 2 most frequent items
        for (int n: nums) {
            if (n == cand1) vote1++;
            else if (n == cand2) vote2++;
            else if (!vote1) {
                cand1 = n;
                vote1++;
            }
            else if (!vote2) {
                cand2 = n;
                vote2++;
            }
            else {
                vote1--;
                vote2--;
            }
        }
        // checking the actual frequency of the 2 most common items
        vote1 = 0;
        vote2 = 0;
        for (int n: nums) {
            if (n == cand1) vote1++;
            if (n == cand2) vote2++;
        }
        // making sure cand1 has more votes
        if (vote1 < vote2) {
            swap(cand1, cand2);
            swap(vote1, vote2);
        }
        return vote1 <= lmt ? vector<int>{} : vote2 <=lmt ? vector<int>{cand1} : vector<int>{cand1, cand2};
}

int main() {
    vector<int> nums {0,-1,2,-1};
    vector<int> answer = majorityElement(nums);

    for (int &iter : answer) {
        cout << iter << " ";
    }
    return 0;
}