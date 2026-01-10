/* 435. Non-overlapping Intervals */
/** Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 * 
 *  Example 1:
 *  Input: [[1,2],[2,3],[3,4],[1,3]]
 *  Output: 1
 *  Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
 * 
 *  Example 2:
 *  Input: [[1,2],[1,2],[1,2]]
 *  Output: 2
 *  Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
 * 
 *  Example 3:
 *  Input: [[1,2],[2,3]]
 *  Output: 0
 *  Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 * 
 *  Note:
 *  You may assume the interval's end point is always bigger than its start point.
 *  Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other. **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (vector<int> &v1, vector<int> &v2) {
    if (v1[1] != v2[1]) {
        return v1[1] < v2[1];
    }

    return v1[0] < v2[0];
}

int eraseOverlapIntervals (vector<vector<int>>& intervals) {
    int prev;
    int answer;

    sort (intervals.begin(), intervals.end(), compare);

    if (intervals.empty() || intervals.size() == 1) return 0;

    prev = intervals[0][1];
    answer = 0;

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < prev) {
            answer++;
        } else {
            prev = intervals[i][1];
        }
    }

    return answer;
}

int main() {
    vector<int> i1 {1,2};
    vector<int> i2 {2,3};
    vector<int> i3 {3,4};
    vector<int> i4 {1,3};

    vector<int> j1 {1,2};
    vector<int> j2 {1,2};
    vector<int> j3 {1,2};

    vector<int> k1 {1,2};
    vector<int> k2 {2,3};

    vector<vector<int>> intervals1 {i1,i2,i3,i4};
    vector<vector<int>> intervals2 {j1,j2,j3};
    vector<vector<int>> intervals3 {k1,k2};

    int answer1 = eraseOverlapIntervals(intervals1); // 1
    int answer2 = eraseOverlapIntervals(intervals2); // 2
    int answer3 = eraseOverlapIntervals(intervals3); // 2

    cout << answer1 << endl;
    cout << answer2 << endl;
    cout << answer3 << endl;

    return 0;
}


