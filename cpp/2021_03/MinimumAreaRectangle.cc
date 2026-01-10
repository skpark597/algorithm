/* 939. Minimum Area Rectangle */
/** Given a set of points in the xy-plane, determine the minimum area of a rectangle formed 
 *  from these points, with sides parallel to the x and y axes.
 *  If there isn't any rectangle, return 0.
 * 
 *  Example 1:
 *  Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
 *  Output: 4
 * 
 *  Example 2:
 *  Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
 *  Output: 2
 * 
 *  Note:
 *  1 <= points.length <= 500
 *  0 <= points[i][0] <= 40000
 *  0 <= points[i][1] <= 40000
 *  All points are distinct. **/

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
#include <iostream>

using namespace std;

// priority queue에서 point를 꺼낼 때, 사전식 순서로 가장 작은 것부터 나오게 할 때 쓰이는 comparator
struct comp1 {
    bool operator() (const pair<int,int> &p1, const pair<int,int> &p2) const {
        if (p1.first != p2.first) return p1.first > p2.first;
        return p1.second > p2.second;
    }
};

struct comp2 {
    bool operator() (const pair<int,int> &p1, const pair<int,int> &p2) const {
        if (p1.second != p2.second) return p1.second < p2.second;
        return p1.first < p2.first;
    }
};

// Solution을 보고 다시 구현한 풀이. 이건 Accepted.
int minAreaRect(vector<vector<int>>& points) {
    int minArea = INT_MAX;
    map<int, vector<int>> cols;
    unordered_map<int, int> codes;

    for (vector<int> iter : points) {
        if (cols.count(iter[0]) == 0) {
            cols[iter[0]] = vector<int> {iter[1]};
        } else {
            cols[iter[0]].push_back(iter[1]);
        }
    }

    for (auto &iter : cols) {
        int xCoord = iter.first;
        vector<int> &yCoord = iter.second;
        sort(yCoord.begin(), yCoord.end());

        for (int i = 0; i < yCoord.size(); ++i) {
            for (int j = i+1; j < yCoord.size(); ++j) {
                int code = 40001 * yCoord[i] + yCoord[j];
                if (codes.count(code) != 0) {
                    int curArea = (yCoord[j] - yCoord[i]) * (xCoord - codes[code]);
                    minArea = min(minArea, curArea);
                } 
                
                codes[code] = xCoord;
            }
        }
    }

    return minArea;
}

// 처음에 구현한 풀이. 너무 brute force로 접근하다보니 Time Limit Exceeded. 이건 좀 아니었던 것 같다.
int minAreaRect2(vector<vector<int>>& points) {
    map<pair<int,int>, bool> map1;
    map<pair<int,int>, bool, comp2> map2;
    map<pair<int,int>, bool>::iterator iter;
    int minArea = INT_MAX;

    for (vector<int> iter : points) {
        map1[make_pair(iter[0], iter[1])] = true;
        map2[make_pair(iter[0], iter[1])] = true;
    }

    for (iter = map1.begin(); iter != map1.end();) {
        bool found = false;
        pair<int,int> cur = iter->first;
        pair<int,int> nextY = map1.upper_bound(cur)->first;
        pair<int,int> nextX = map2.upper_bound(cur)->first;

        while (cur.first == nextY.first) {
            pair<int,int> nextNextX = nextX;
            while (cur.second == nextNextX.second) {
                if (map2.count(make_pair(nextNextX.first, nextY.second)) != 0) {
                    int curArea = (nextY.second - cur.second) * (nextNextX.first - cur.first);
                    minArea = min(minArea, curArea);
                    found = true;
                    break;
                }

                nextNextX = map2.upper_bound(nextNextX)->first;
            }
            
            if (found) break;
            nextY = map1.upper_bound(nextY)->first;
        }

        iter = map1.erase(iter);
    }

    return minArea == INT_MAX ? 0 : minArea;
}

int main() {
    map<int, bool> m;
    map<pair<int,int>, bool> map2;
    map<pair<int,int>, bool, comp2> map1;

    m[1] = true;
    m[2] = true;
    m[3] = true;

    priority_queue<pair<int,int>, vector<pair<int,int>>, comp1> pq1;
    map1[make_pair(1,1)] = true;
    map1[make_pair(1,2)] = true;
    map1[make_pair(2,1)] = true;
    map1[make_pair(3,-1)] = true;

    map2[make_pair(1,1)] = true;
    map2[make_pair(1,2)] = true;
    map2[make_pair(2,1)] = true;
    map2[make_pair(3,-1)] = true;

    // for (auto & iter : m) {
    //     cout << iter.first << ", " << endl;
    // }

    auto test = map1.upper_bound(make_pair(3,-1));
    auto test1 = map1.upper_bound(make_pair(1,1));
    auto test2 = map1.upper_bound(make_pair(2,1));
    auto test3 = map1.upper_bound(make_pair(1,2));

    //if (test3 == map1.end()) cout << "end" << endl;

    pq1.push(make_pair(1,1));
    pq1.push(make_pair(1,2));
    pq1.push(make_pair(2,1));
    pq1.push(make_pair(3,-1));

    pair<int,int> t1 = pq1.top();
    pq1.pop();
    pair<int,int> t2 = pq1.top();
    pq1.pop();
    pair<int,int> t3 = pq1.top();
    pq1.pop();

    vector<int> point00 {1,1};
    vector<int> point01 {1,3};
    vector<int> point02 {3,1};
    vector<int> point03 {3,3};
    vector<int> point04 {2,2};
    vector<vector<int>> point0 {point00, point01, point02, point03, point04};

    vector<int> point10 {1,1};
    vector<int> point11 {1,3};
    vector<int> point12 {3,1};
    vector<int> point13 {3,3};
    vector<int> point14 {4,1};
    vector<int> point15 {4,3};
    vector<vector<int>> point1 {point10, point11, point12, point13, point14, point15};

    vector<int> point20 {0,1};
    vector<int> point21 {1,3};
    vector<int> point22 {3,3};
    vector<int> point23 {4,4};
    vector<int> point24 {1,4};
    vector<int> point25 {2,3};
    vector<int> point26 {1,0};
    vector<int> point27 {3,4};
    vector<vector<int>> point2 {point20, point21, point22, point23, point24, point25, point26, point27};

    int ans0 = minAreaRect(point0);
    int ans1 = minAreaRect(point1);
    int ans2 = minAreaRect(point2);

    cout << ans0 << endl; // 4
    cout << ans1 << endl; // 2
    cout << ans2 << endl; // 2

    return 0;
}