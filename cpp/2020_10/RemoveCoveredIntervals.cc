/*1288. Remove Covered Intervals */
/** Given a list of intervals, remove all intervals that are covered by another interval in the list.
 *  Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.
 *  After doing so, return the number of remaining intervals.
 *  
 *  Example 1:
 *  Input: intervals = [[1,4],[3,6],[2,8]]
 *  Output: 2
 *  Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
 * 
 *  Example 2:
 *  Input: intervals = [[1,4],[2,3]]
 *  Output: 1
 * 
 *  Example 3:
 *  Input: intervals = [[0,10],[5,12]]
 *  Output: 2
 * 
 *  Example 4:
 *  Input: intervals = [[3,10],[4,10],[5,11]]
 *  Output: 2
 * 
 *  Example 5:
 *  Input: intervals = [[1,2],[1,4],[3,4]]
 *  Output: 1
 * 
 *  Constraints:
 *  1 <= intervals.length <= 1000
 *  intervals[i].length == 2
 *  0 <= intervals[i][0] < intervals[i][1] <= 10^5
 *  All the intervals are unique. **/

/** 온라인 채점 겨우 통과함. 효율 개구림 **/

#include <vector>
#include <iostream>
using namespace std;

int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int count = intervals.size();
    vector<bool> removed (count, false);
    
    for (int i=0; i < intervals.size(); ++i) {
        for (int j=0; j < intervals.size(); ++j) {
            if (!removed[j] && j != i) {
                if (intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]) {
                    removed[j] = true;
                    count--;
                }
            }
        }
    }

    return count;
}

int main() {
    vector<int> inter1 {3, 10};
    vector<int> inter2 {4, 10};
    vector<int> inter3 {5, 11};

    vector<vector<int>> intervals;
    intervals.push_back(inter1);
    intervals.push_back(inter2);
    intervals.push_back(inter3);
    int answer = removeCoveredIntervals(intervals);

    cout << answer << endl;

    return 0;
}






