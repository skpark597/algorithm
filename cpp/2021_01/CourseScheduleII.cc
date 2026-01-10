/* 210. Course Schedule II */
/** There are a total of n courses you have to take labelled from 0 to n - 1.
 *  Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.
 *  Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.
 *  If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
 * 
 *  Example 1:
 *  Input: numCourses = 2, prerequisites = [[1,0]]
 *  Output: [0,1]
 *  Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
 * 
 *  Example 2:
 *  Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 *  Output: [0,2,1,3]
 *  Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
 *  So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
 * 
 *  Example 3:
 *  Input: numCourses = 1, prerequisites = []
 *  Output: [0]
 * 
 *  Constraints:
 *  1 <= numCourses <= 2000
 *  0 <= prerequisites.length <= numCourses * (numCourses - 1)
 *  prerequisites[i].length == 2
 *  0 <= ai, bi < numCourses
 *  ai != bi
 *  All the pairs [ai, bi] are distinct. **/
/* bfs와 dfs를 둘 다 구현하였음 */

#include <vector>
#include <queue>
#include <iostream>
#include <limits.h>

using namespace std;

vector<vector<int>> adj;
vector<int> indegree; // bfs 이용시 쓰임
vector<int> status; // dfs 이용시 쓰임

void initBFS(int total, vector<vector<int>> &prerequisites) {
    adj.clear();
    indegree.clear();
    adj.resize(total);
    indegree.resize(total, 0);

    for (int i = 0; i < prerequisites.size(); ++i) {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }
}

void bfs(int total, vector<int> &answer) {
    queue<int> queue;

    for (int i = 0; i < total; ++i) {
        if (indegree[i] == 0) queue.push(i);
    }

    while (!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        answer.push_back(cur);

        for (int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i];
            indegree[next]--;
            if (indegree[next] == 0) queue.push(next);
        }
    }
}

void initDFS(int total, vector<vector<int>> &prerequisites) {
    adj.clear();
    status.clear();
    adj.resize(total);
    status.resize(total, 0);

    for (int i = 0; i < prerequisites.size(); ++i) {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
}

bool dfs(int index, vector<int> &answer) {
    status[index] = 2;

    for (int i = 0; i < adj[index].size(); ++i) {
        int next = adj[index][i];
        if (status[next] == 1) {
            continue;
        } else if (status[next] == 2) {
            return true;
        } else {
            if (dfs(next, answer)) return true;
        }
    }

    status[index] = 1;
    answer.push_back(index);
    return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> answer;
    bool hasCycle = false;
    initDFS(numCourses, prerequisites);

    for (int i = 0; i < numCourses; ++i) {
        if (status[i] == 0) {
            if (dfs(i, answer)) return vector<int>();
        }
    }

    return answer;
}

//vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
//    vector<int> answer;
//
//    initBFS(numCourses, prerequisites);
//    bfs(numCourses, answer);
//    
//    for (int i = 0; i < indegree.size(); ++i) {
//        if (indegree[i] != 0) return vector<int>();
//    }
//
//    return answer;
//}

int main() {
    int numCourses0 = 4;
    vector<int> pre00 {1,0};
    vector<int> pre01 {2,0};
    vector<int> pre02 {3,1};
    vector<int> pre03 {3,2};
    vector<vector<int>> pre0 {pre00, pre01, pre02, pre03};

    vector<int> ans0 = findOrder(numCourses0, pre0);

    int numCourses1 = 2;
    vector<int> pre10 {1,0};
    vector<vector<int>> pre1 {pre10};

    vector<int> ans1 = findOrder(numCourses1, pre1);

    int numCourses2 = 3;
    vector<int> pre20 {0,1};
    vector<int> pre21 {0,2};
    vector<int> pre22 {1,2};
    vector<vector<int>> pre2 {pre20, pre21, pre22};

    vector<int> ans2 = findOrder(numCourses2, pre2);

    for (int iter : ans0) {
        cout << iter << " ";
    }
    cout << endl; // 0213  0123

    for (int iter : ans1) {
        cout << iter << " ";
    }
    cout << endl; // 01

    for (int iter : ans2) {
        cout << iter << " ";
    }
    cout << endl; // 210

    return 0;
}


