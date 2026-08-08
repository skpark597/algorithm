/** 207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array
prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course
ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it
is impossible.

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique. */

#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool findCycle(int cur, int numCourses, unordered_map<int, vector<int>>& adjs, unordered_set<int>& visited,
               unordered_set<int>& inStack) {
  visited.insert(cur);
  inStack.insert(cur);

  for (int next : adjs[cur]) {
    if (inStack.count(next) > 0) return true;
    if (visited.count(next) > 0) continue;
    if (findCycle(next, numCourses, adjs, visited, inStack)) return true;
  }

  inStack.erase(cur);
  return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  unordered_map<int, vector<int>> adjs;
  unordered_set<int> visited;
  unordered_set<int> inStack;

  for (vector<int>& prerequisite : prerequisites) {
    int from = prerequisite[1], to = prerequisite[0];

    if (adjs.count(from) == 0) {
      adjs[from] = vector<int>{to};
    } else {
      adjs[from].push_back(to);
    }
  }

  for (int cur = 0; cur < numCourses; ++cur) {
    if (visited.count(cur) > 0) continue;
    if (findCycle(cur, numCourses, adjs, visited, inStack)) return false;
  }

  return true;
}

int main() {
  vector<vector<int>> prerequisites0{{1, 0}};
  vector<vector<int>> prerequisites1{{1, 0}, {0, 1}};
  vector<vector<int>> prerequisites2{{1, 0}, {3, 0}, {3, 1}, {2, 1}, {4, 2}};
  vector<vector<int>> prerequisites3{{1, 0}, {3, 0}, {3, 1}, {1, 2}, {4, 3}, {2, 4}};
  vector<vector<int>> prerequisites4{{0, 1}, {0, 2}, {1, 2}};

  bool ret0 = canFinish(2, prerequisites0);
  bool ret1 = canFinish(2, prerequisites1);
  bool ret2 = canFinish(5, prerequisites2);
  bool ret3 = canFinish(5, prerequisites3);
  bool ret4 = canFinish(3, prerequisites4);

  assert(ret0 == true);
  assert(ret1 == false);
  assert(ret2 == true);
  assert(ret3 == false);
  assert(ret4 == true);

  return 0;
}