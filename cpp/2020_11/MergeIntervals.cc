/* 56. Merge Intervals */
/** Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping intervals, 
 *  and return an array of the non-overlapping intervals that cover all the intervals in the input.
 * 
 *  Example 1:
 *  Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 *  Output: [[1,6],[8,10],[15,18]]
 *  Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * 
 *  Example 2:
 *  Input: intervals = [[1,4],[4,5]]
 *  Output: [[1,5]]
 *  Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *  
 *  Constraints:
 *  1 <= intervals.length <= 10^4
 *  intervals[i].length == 2
 *  0 <= start_i <= end_i <= 10^4  **/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int start = -1;
    int end  = -1;
    vector<vector<int>> answer;

    sort(intervals.begin(), intervals.end());

    if (intervals.empty()) return answer;

    start = intervals[0][0];
    end = intervals[0][1];

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
        } else {
            vector<int> merged_interval {start, end};
            answer.push_back(merged_interval);
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    vector<int> final_interval {start, end};
    answer.push_back(final_interval);

    return answer;
}

int main() {
    //vector<int> interval1 {1,3};
    //vector<int> interval2 {2,6};
    //vector<int> interval3 {8,10};
    //vector<int> interval4 {15,18};
    vector<int> interval1 {1,4};
    vector<int> interval2 {4,5};
    vector<vector<int>> intervals {interval1, interval2};

    vector<vector<int>> answer = merge(intervals);

    for (int i = 0; i < answer.size(); ++i) {
        cout <<"[" << answer[i][0] << ", " << answer[i][1] << "]" << endl;
    }

    return 0;
}



