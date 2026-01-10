/* 57. Insert Interval */
/** Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *  You may assume that the intervals were initially sorted according to their start times.
 * 
 *  Example 1
 *  Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 *  Output: [[1,5],[6,9]]
 * 
 *  Example 2
 *  Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 *  Output: [[1,2],[3,10],[12,16]
 * 
 *  Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10]
 *  input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 *  **/

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int isIn (int point, vector<int> &interval) {
    int start = interval.front();
    int end = interval.back();

    if (point < start) {
        return -1;
    } else if (point >= start && point <= end) {
        return 0;
    } else {
        return 1;
    }
}

vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
    vector<vector<int> > answer;
    vector<int> mergedInterval;
    int start = newInterval.front();
    int end = newInterval.back();
    float overlapStart = intervals.size();
    float overlapEnd = intervals.size();
    int discriminant;

    if (intervals.empty()) {
        answer.push_back(newInterval);
        return answer;
    }

    for (int i=0; i < intervals.size(); ++i) {
        discriminant = isIn (start, intervals[i]);
        if (discriminant != 1) {
            overlapStart = i;
            start = min (start, intervals[i].front());
            break;
        }
    }

    for (int i=overlapStart; i< intervals.size(); ++i) {
        discriminant = isIn(end, intervals[i]);
        if (discriminant == 0) {
            overlapEnd = i;
            end = max (end, intervals[i].back());
            break;
        } else if (discriminant == -1) {
            overlapEnd = i-0.5;
            break;
        }
    }

    mergedInterval.push_back(start);
    mergedInterval.push_back(end);

    for (int i=0; i < overlapStart; ++i) {
        answer.push_back(intervals[i]);
    }
    answer.push_back(mergedInterval);

    for (int i=overlapEnd+1; i < intervals.size(); ++i) {
        answer.push_back(intervals[i]);
    }

    return answer;
}

int main() {
    vector<vector<int> > intervals;
    vector<int> newInt;
    vector<int> int1;
    vector<int> int2;
    vector<int> int3;
    vector<int> int4;
    vector<int> int5;
    int1.push_back(1);
    int1.push_back(5);
    //int2.push_back(3);
    //int2.push_back(5);
    //int3.push_back(6);
    //int3.push_back(7);
    //int4.push_back(8);
    //int4.push_back(10);
    //int5.push_back(12);
    //int5.push_back(16);
    intervals.push_back(int1);
    //intervals.push_back(int2);
    //intervals.push_back(int3);
    //intervals.push_back(int4);
    //intervals.push_back(int5);
    newInt.push_back(6);
    newInt.push_back(8);    

    vector<vector<int> > answer = insert (intervals, newInt);

    for (int i=0; i < answer.size(); ++i) {
        cout << answer[i].front() << "," << answer[i].back() <<endl;
    }

    return 0;
}


