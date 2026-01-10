/* 347. Top K Frequent Elements */
/** Given a non-empty array of integers, return the k most frequent elements.
 *  Example 1:
 *  Input: nums = [1,1,1,2,2,3], k = 2
 *  Output: [1,2]
 *  
 *  Example 2:
 *  Input: nums = [1], k = 1
 *  Output: [1]
 * 
 *  Note:
 *  You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 *  Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 *  It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
 *  You can return the answer in any order. */

#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> answer;
    unordered_map<int,int> map;
    priority_queue<pair<int,int>> pq;

    for (int iter : nums) {
        if (map.count(iter) == 0) {
            map[iter] = 1;
        } else {
            map[iter]++;
        }
    }

    for (auto iter = map.begin(); iter != map.end(); ++iter) {
        pq.push(make_pair(iter->second, iter->first));
    }

    for (int i = 0; i < k; ++i) {
        answer.push_back(pq.top().second);
        pq.pop();
    }

    return answer;
}

int main() {
    vector<int> nums0 {1,1,1,2,2,3};
    vector<int> ans0 = topKFrequent(nums0, 2);

    vector<int> nums1 {1};
    vector<int> ans1 = topKFrequent(nums1, 1);

    vector<int> nums2 {1,2};
    vector<int> ans2 = topKFrequent(nums2, 2);

    for (int iter : ans0) {
        cout << iter << " ";
    }
    cout << endl; // 1 2

    for (int iter : ans1) {
        cout << iter << " ";
    }
    cout << endl; // 1

    for (int iter : ans2) {
        cout << iter << " ";
    }
    cout << endl; // 1 2
    return 0;
}