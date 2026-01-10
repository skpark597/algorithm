/* 1631. Path With Minimum Effort */
/** You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
 *  where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), 
 *  and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, 
 *  and you wish to find a route that requires the minimum effort.
 * 
 *  A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
 *  Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
 * 
 *  Example 1:
 *  Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
 *  Output: 2
 *  Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
 *  This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
 * 
 *  Example 2:
 *  Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
 *  Output: 1
 *  Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
 * 
 *  Example 3:
 *  Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
 *  Output: 0
 *  Explanation: This route does not require any effort.
 * 
 *  Constraints:
 *  rows == heights.length
 *  columns == heights[i].length
 *  1 <= rows, columns <= 100
 *  1 <= heights[i][j] <= 10^6 **/

/* Dijkstra Algorithm 쓰는 것을 처음 알게해준 문제. Leetcode Discussion 참고함 */

#include <iostream>
#include <vector>
#include <list>
#include <limits.h>

using namespace std;

vector<vector<int>> direction {{-1,0}, {1,0}, {0,1}, {0,-1}};

int minimumEffortPath(vector<vector<int>>& heights) {
    int rows = heights.size();
    int columns;
    list<pair<int,int>> vertices;
    vector<vector<int>> costs;

    if (rows == 0) return 0;
    columns = heights[0].size();
    costs.resize (rows, vector<int>(columns, INT_MAX));
    vertices.push_back(make_pair(0,0));
    costs[0][0] = 0;

    while (!vertices.empty()) {
        int x = vertices.front().first;
        int y = vertices.front().second;
        int cost = costs[x][y];
        vertices.pop_front();

        for (int i = 0; i < 4; ++i) {
            int new_x = x + direction[i][0];
            int new_y = y + direction[i][1];
            int new_cost;

            if (new_x < 0 || new_x >= rows || new_y < 0 || new_y >= columns) continue;

            new_cost = max(cost, abs(heights[new_x][new_y] - heights[x][y]));
            if (costs[new_x][new_y] <= new_cost) continue;
            costs[new_x][new_y] = new_cost;
            vertices.push_back(make_pair(new_x, new_y));
        }
    }

    return costs[rows-1][columns-1];
}

int main() {
    vector<int> first {1,2,2};
    vector<int> second {3,8,2};
    vector<int> third {5,3,5};
    vector<vector<int>> height {first, second, third};

    vector<int> first1 {1,2,3};
    vector<int> second1 {3,8,4};
    vector<int> third1 {5,3,5};
    vector<vector<int>> height1 {first1, second1, third1};

    vector<int> first2 {1,2,1,1,1};
    vector<int> second2 {1,2,1,2,1};
    vector<int> third2 {1,2,1,2,1};
    vector<int> fourth2 {1,2,1,2,1};
    vector<int> fifth2 {1,1,1,2,1};
    vector<vector<int>> height2 {first2, second2, third2, fourth2, fifth2};

    int answer = minimumEffortPath (height);
    int answer1 = minimumEffortPath (height1);
    int answer2 = minimumEffortPath (height2);

    cout << answer << endl;  // 2
    cout << answer1 << endl;  // 1
    cout << answer2 << endl;  // 0

    return 0;
}



