/* 436. Find Right Interval */
/** You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.
 *  The right interval for an interval i is an interval j such that startj >= endi and startj is minimized.
 *  Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.
 * 
 *  Example 1:
 *  Input: intervals = [[1,2]]
 *  Output: [-1]
 *  Explanation: There is only one interval in the collection, so it outputs -1.
 * 
 *  Example 2:
 *  Input: intervals = [[3,4],[2,3],[1,2]]
 *  Output: [-1,0,1]
 *  Explanation: There is no right interval for [3,4].
 *  The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
 *  The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.
 * 
 *  Example 3:
 *  Input: intervals = [[1,4],[2,3],[3,4]]
 *  Output: [-1,2,-1]
 *  Explanation: There is no right interval for [1,4] and [3,4].
 *  The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start that is >= end1 = 3.
 * 
 *  Constraints:
 *  1 <= intervals.length <= 2 * 10^4
 *  intervals[i].length == 2
 *  -10^6 <= starti <= endi <= 10^6
 *  The start point of each interval is unique. **/

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Triple {
    public:
    int num;
    bool isRight;
    int index;
    Triple(int n, bool isR, int i) {
        num = n;
        isRight = isR;
        index = i;
    }
};

bool comp(Triple *t1, Triple *t2) {
    if (t1->num != t2->num) {
        return t1->num < t2->num;
    } else if (t1->isRight != t2->isRight) {
        return t1->isRight == true && t2->isRight == false;
    }

    return true;
}

vector<int> findRightInterval(vector<vector<int>> &intervals) {
    vector<int> answer (intervals.size(), -1);
    vector<Triple *> triples;
    stack<int> st;

    if (intervals.empty()) return vector<int>();

    for (int i = 0; i < intervals.size(); ++i) {
        for (int j = 0; j < 2; ++j) {
            Triple triple (intervals[i][j], true, i);
            triples.push_back(new Triple(intervals[i][j], j, i));
        }
    }

    sort(triples.begin(), triples.end(), comp);

    for (int i = 0; i < triples.size(); ++i) {
        if (triples[i]->isRight) {
            st.push(triples[i]->index);
            continue;
        }
        
        while (!st.empty()) {
            answer[st.top()] = triples[i]->index;
            st.pop();
        }
    }

    for (int i = 0 ; i < triples.size(); ++i) {
        delete triples[i];
    }

    return answer;
}

int main() {
    vector<int> interval00 {1,2};
    vector<vector<int>> interval0 {interval00};
    vector<int> ans0 = findRightInterval(interval0);
    
    vector<int> interval10 {3, 4};
    vector<int> interval11 {2, 3};
    vector<int> interval12 {1, 2};
    vector<vector<int>> interval1 {interval10, interval11, interval12};
    vector<int> ans1 = findRightInterval(interval1);

    vector<int> interval20 {1,4};
    vector<int> interval21 {2,3};
    vector<int> interval22 {3,4};
    vector<vector<int>> interval2 {interval20, interval21, interval22};
    vector<int> ans2 = findRightInterval(interval2);

    for (int i = 0; i < ans0.size(); ++i) {
        cout << ans0[i] << " ";
    }
    cout << endl; // -1

    for (int i = 0; i < ans1.size(); ++i) {
        cout << ans1[i] << " ";
    }
    cout << endl; // -1 0 1

    for (int i = 0; i < ans2.size(); ++i) {
        cout << ans2[i] << " ";
    }
    cout << endl; // -1 2 -1

    return 0;
}


