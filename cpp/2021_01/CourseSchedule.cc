/* 207. Course Schedule */
/** There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
 *  Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 *  Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 *  
 *  Example 1:
 *  Input: numCourses = 2, prerequisites = [[1,0]]
 *  Output: true
 *  Explanation: There are a total of 2 courses to take. 
 *               To take course 1 you should have finished course 0. So it is possible.
 * 
 *  Example 2:
 *  Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 *  Output: false
 *  Explanation: There are a total of 2 courses to take. 
 *  To take course 1 you should have finished course 0, and to take course 0 you should
 *  also have finished course 1. So it is impossible.
 * 
 *  Constraints:
 *  The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 *  You may assume that there are no duplicate edges in the input prerequisites.
 *  1 <= numCourses <= 10^5 **/

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

vector<list<int>> adj;
vector<bool> visited;
vector<bool> finished;
bool hasCycle;
int cnt;

void init(int numCourses) {
    cnt = 0;
    hasCycle = false;
    adj.clear();
    visited.clear();
    finished.clear();
    adj.resize(numCourses);
    visited.resize(numCourses, false);
    finished.resize(numCourses, false);
}

void dfs(int num) {
    visited[num] = true;

    for (int iter : adj[num]) {
        if (!visited[iter]) {
            dfs(iter);
        } else if (!finished[iter]) {
            hasCycle = true;
        }
    }

    finished[num] = true;
    cnt++;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    init(numCourses);

    for (int i = 0; i < prerequisites.size(); ++i) {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }

    for (int i = 0; i < numCourses; ++i) {
        if (!visited[i]) dfs(i);
        if (hasCycle) return false;
    }

    return cnt == numCourses;
}

int main() {
    int num0 = 2;
    vector<int> edge00 {1,0};
    vector<vector<int>> pre0 {edge00};

    bool ans0 = canFinish(num0, pre0);

    int num1 = 2;
    vector<int> edge10 {1,0};
    vector<int> edge11 {0,1};
    vector<vector<int>> pre1 {edge10, edge11};

    bool ans1 = canFinish(num1, pre1);

    int num2 = 2;
    vector<vector<int>> pre2;

    bool ans2 = canFinish(num2, pre2);

    cout << ans0 << endl;
    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}

