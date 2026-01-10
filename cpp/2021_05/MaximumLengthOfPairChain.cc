/** 646. Maximum Length of Pair Chain */ 
/** You are given an array of n pairs pairs where pairs[i] = [left_i, right_i] and left_i < right_i.
 *  A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.\
 *  Return the length longest chain which can be formed.
 *  You do not need to use up all the given intervals. You can select pairs in any order.
 * 
 *  Example 1:
 *  Input: pairs = [[1,2],[2,3],[3,4]]
 *  Output: 2
 *  Explanation: The longest chain is [1,2] -> [3,4].
 * 
 *  Example 2:
 *  Input: pairs = [[1,2],[7,8],[4,5]]
 *  Output: 3
 *  Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 * 
 *  Constraints:
 *  n == pairs.length
 *  1 <= n <= 1000
 *  -1000 <= left_i < right_i < 1000 **/

#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

struct myclass {
    inline bool operator() (vector<vector<int>> &pair0, vector<vector<int>> &pair1) {
        if (pair0[1] != pair1[1]) return pair0[1] < pair1[1];
        return pair0[0] <= pair1[0];
    }
} myobject;

bool compare(vector<int> &pair0, vector<int> &pair1) {
    if (pair0[1] != pair1[1]) return pair0[1] < pair1[1];
    return pair0[0] <= pair1[0];
}

int findLongestChain(vector<vector<int>>& pairs) {
    int answer = 0;
    int right = INT_MIN;
    sort(pairs.begin(), pairs.end(), compare);

    for (int i = 0; i < pairs.size(); ++i) {
        if (pairs[i][0] > right) {
            answer++;
            right = pairs[i][1];
        }
    }

    return answer;
}

int main() {
    vector<int> pair00 {1,2};
    vector<int> pair01 {2,3};
    vector<int> pair02 {3,4};
    vector<vector<int>> pairs0 {pair00, pair01, pair02};

    vector<int> pair10 {1,2};
    vector<int> pair11 {7,8};
    vector<int> pair12 {4,5};
    vector<vector<int>> pairs1 {pair10, pair11, pair12};

    vector<int> pair20 {-6,9};
    vector<int> pair21 {1,6};
    vector<int> pair22 {8,10};
    vector<int> pair23 {-1,4};
    vector<int> pair24 {-6,-2};
    vector<int> pair25 {-9,8};
    vector<int> pair26 {-5,3};
    vector<int> pair27 {0,3};
    vector<vector<int>> pairs2 {pair20, pair21, pair22, pair23, pair24, pair25, pair26, pair27};

    int ans0 = findLongestChain(pairs0);
    int ans1 = findLongestChain(pairs1);
    int ans2 = findLongestChain(pairs2);

    cout << ans0 << endl; // 2
    cout << ans1 << endl; // 3
    cout << ans2 << endl; // 3

    return 0;
}

