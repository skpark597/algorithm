/* 327. Count of Range Sum */
/** Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
 *  Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
 * 
 *  Note: A naive algorithm of O(n^2) is trivial. You MUST do better than that.
 *  Example:
 *  Input: nums = [-2,5,-1], lower = -2, upper = 2,
 *  Output: 3 
 *  Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.
 *  Constraints: 0 <= nums.length <= 10^4 **/

/** Discussion을 보고 구현한 풀이... 어렵네 **/

#include <vector>
#include <algorithm>
#include <limits.h>
#include <iostream>
#include <map>

using namespace std;

class FenwickTree {
    private:
    vector<int> tree;
    public:
    FenwickTree(int size) {
        tree.resize(size+1, 0);
    }
    int sum(int index) {
        int ret = 0;
        int pos = index+1;

        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos-1);
        }

        return ret;
    }

    void add(int index, int val) {
        int pos = index+1;

        while (pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};


int countRangeSum(vector<int> &nums, int lower, int upper) {
    int size = nums.size();
    int answer = 0;
    int index = 0;
    long sum = 0;
    vector<long> cand;
    map<long, int> hash;
    FenwickTree fenwickTree(3 * (size + 1));

    cand.push_back(0);
    cand.push_back(-(long)lower);
    cand.push_back(-(long)upper);
    for (int num : nums) {
        sum += num;
        cand.push_back(sum);
        cand.push_back(sum-(long)lower);
        cand.push_back(sum-(long)upper);
    }

    sort(cand.begin(), cand.end());

    for (long num : cand) {
        hash[num] = index++;
    }

    sum = 0;
    fenwickTree.add(hash[0], 1);
    for (int num : nums) {
        sum += (long)num;
        answer += fenwickTree.sum(hash[sum-lower]);
        answer -= fenwickTree.sum(hash[sum-upper]-1);
        fenwickTree.add(hash[sum], 1);
    }

    return answer;
}

int main() {
    vector<int> nums0 {-2,5,-1};
    int ans0 = countRangeSum(nums0, -2, 2);

    cout << ans0 << endl; // 3
    return 0;
}




